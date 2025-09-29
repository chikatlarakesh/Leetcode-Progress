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
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxRow = 0,maxCol = 0;

        for(auto &stone: stones) {
            int x = stone[0];
            int y = stone[1];
            maxRow = max(maxRow,x);
            maxCol = max(maxCol,y);
        }

        DisjointSet ds(maxRow + maxCol + 1);
        unordered_map<int,int> nodes;
        for(auto &stone: stones) {
            int x = stone[0];
            int y = stone[1] + maxRow + 1;
            if(ds.findUPar(x) != ds.findUPar(y)) {
                ds.UnionBySize(x,y);
                nodes[x] = 1;
                nodes[y] = 1;
            }
        }

        int components = 0;
        for(auto &it: nodes) {
            if(ds.findUPar(it.first) == it.first) components++;
        }
        return n - components;
    }
};