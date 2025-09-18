class Solution {
public:
    void visitConnectedCities(int node,vector<vector<int>>& adj,vector<int>& visited) {
        visited[node] = 1;
        for(auto &it: adj[node]) {
            if(!visited[it]) {
                visitConnectedCities(it,adj,visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n+1);

        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(i != j) {
                    if(isConnected[i][j] == 1) {
                        adj[i+1].push_back(j+1);
                    }
                }
            }
        }

        int provinces = 0;
        vector<int> visited(n+1,0);
        for(int i=1;i<=n;i++) {
            if(!visited[i]) {
                provinces++;
                visitConnectedCities(i,adj,visited);
            }
        }
        return provinces;
    }
};