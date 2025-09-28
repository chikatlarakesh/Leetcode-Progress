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
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m = connections.size();
        //if(m < n-1) return -1;
        int extraEdges = 0;
        DisjointSet ds(n);
        for(int i=0;i<m;i++) {
            int node = connections[i][0];
            int adjNode = connections[i][1];
            if(ds.findUPar(node) != ds.findUPar(adjNode)) {
                ds.UnionBySize(node,adjNode);
            }
            else extraEdges++;
        }
        int components = 0;
        for(int i=0;i<n;i++) {
            if(ds.parent[i] == i) components++;
        }
        int requiredEdges = components - 1;

        if(extraEdges < requiredEdges) return -1;
        return requiredEdges;
    }
};