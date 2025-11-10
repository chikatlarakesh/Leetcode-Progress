class Solution {
public:
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

    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        int n = connections.size();
        DisjointSet ds(c+1);
        unordered_map<int,set<int>> mp;

        for(auto &edge: connections) {
            int u = edge[0];
            int v = edge[1];
            if(ds.findUPar(u) != ds.findUPar(v)) {
                ds.UnionByRank(u,v);
            }
        }

        for(int i=1;i<=c;i++) {
            mp[ds.findUPar(i)].insert(i);
        }

        vector<int> result;
        for(auto &query: queries) {
            int signal = query[0];
            int node = query[1];

            int parent = ds.findUPar(node);
            if(signal == 2) {
                mp[parent].erase(node);
            }
            else {
                if(mp[parent].count(node)) {
                    result.push_back(node);
                }
                else {
                    if(mp[parent].empty()) result.push_back(-1);
                    else result.push_back(*mp[parent].begin());
                }
            }
        }
        return result;
    }
};