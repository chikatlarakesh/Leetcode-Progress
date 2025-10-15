class Solution {
public:
    void dfs(int node, vector<int>& visited,vector<vector<int>>& adj) {
        visited[node] = 1;

        for(auto &it: adj[node]) {
            if(!visited[it]) {
                dfs(it,visited,adj);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);

        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(i!=j && isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                }
            }
        }

        int provinces = 0;
        vector<int> visited(n,0);
        for(int i=0;i<n;i++) {
            if(!visited[i]) {
                provinces++;
                dfs(i,visited,adj);
            }
        }
        return provinces;
    }
};