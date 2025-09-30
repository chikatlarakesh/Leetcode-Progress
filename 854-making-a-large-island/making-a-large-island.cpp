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
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
        vector<pair<int,int>> dir = {{0,-1},{-1,0},{0,1},{1,0}};
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j] == 1) {
                    int row = i;
                    int col = j;
                    for(auto &[x,y]: dir) {
                        int r = row + x;
                        int c = col + y;

                        if(r>=0 && r<n && c>=0 && c<n && grid[r][c]) {
                            int island = (row * n) + col;
                            int adjIsland = (r * n) + c;
                            if(ds.findUPar(island) != ds.findUPar(adjIsland)) {
                                ds.UnionBySize(island,adjIsland);
                            }
                        }
                    }
                }
            }
        }

        int maxSize = 0;
        bool hasZero = false;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                int size = 0;
                unordered_set<int> st;
                if(grid[i][j] == 0) {
                    hasZero = true;
                    int row = i;
                    int col = j;
                    for(auto &[x,y]: dir) {
                        int r = row + x;
                        int c = col + y;

                        if(r>=0 && r<n && c>=0 && c<n && grid[r][c]) {
                            int adjIsland = (r * n) + c;
                            int UPar = ds.findUPar(adjIsland);
                            if(st.find(UPar) == st.end()) {
                                st.insert(UPar);
                                size += ds.size[UPar];
                            }
                        }
                    }
                }
                maxSize = max(maxSize, size+1);
            }
        }
        if(!hasZero) maxSize = n * n;
        return maxSize;
    }
};