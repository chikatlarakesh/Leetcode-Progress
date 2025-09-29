class DisjointSet {
public:
	vector<int> rank, parent, size;

	DisjointSet(int n) {
		rank.resize(n+1,1);
		parent.resize(n+1);
		size.resize(n+1,1);
		for(int i=0;i<=n;i++) {
			parent[i] = i;
		}
	}

	int findUPar(int node) {
		if(node == parent[node]) return node;
		return parent[node] = findUPar(parent[node]);
	}

	void UnionByRank(int u,int v) {
	 	int ulp_u = findUPar(u);
	 	int ulp_v = findUPar(v);

	 	if(ulp_u == ulp_v) return;

	 	if(rank[ulp_u] > rank[ulp_v]) {
	 		parent[ulp_v] = ulp_u;
	 	}
	 	else if(rank[ulp_v] > rank[ulp_u]) {
	 		parent[ulp_u] = ulp_v;
	 	}
	 	else {
	 		parent[ulp_u] = ulp_v;
	 		rank[ulp_v]++;
	 	}
	}

	void UnionBySize(int u,int v) {
		int ulp_u = findUPar(u);
	 	int ulp_v = findUPar(v);

	 	if(ulp_u == ulp_v) return;

	 	if(size[ulp_u] > size[ulp_v]) {
	 		parent[ulp_v] = ulp_u;
	 		size[ulp_u] += size[ulp_v];
	 	}
	 	else {
	 		parent[ulp_u] = ulp_v;
	 		size[ulp_v] += size[ulp_u];
	 	}
	}
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string,int> mapMailNode;

        for(int i=0;i<n;i++) {
            int m = accounts[i].size();
            for(int j=1;j<m;j++) {
                string email = accounts[i][j];
                if(mapMailNode.find(email) == mapMailNode.end()) {
                    mapMailNode[email] = i;
                }
                else {
                    ds.UnionBySize(mapMailNode[email],i);
                }
            }
        }

        vector<vector<string>> mergedEmails(n);
        for(auto &it: mapMailNode) {
            string email = it.first;
            int node = ds.findUPar(it.second);
            mergedEmails[node].push_back(email);
        }

        vector<vector<string>> result;
        for(int i=0;i<n;i++) {
            if(mergedEmails[i].empty()) continue;
            string name = accounts[i][0];
            sort(mergedEmails[i].begin(),mergedEmails[i].end());
            vector<string> temp;
            temp.push_back(name);
            for(auto &it: mergedEmails[i]) {
                temp.push_back(it);
            }
            result.push_back(temp);
        }
        return result;
    }
};