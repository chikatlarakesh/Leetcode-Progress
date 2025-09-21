class Solution {
public:
    bool dfs(int node, int color,vector<int>& visited,vector<vector<int>>& adj) {

        visited[node] = color;

        for(auto &it: adj[node]) {
            if(visited[it] == -1) {
                int newColor = (color == 0) ? 1 : 0;
                if(dfs(it,newColor,visited,adj) == false) return false;
            }
            else if(visited[it] == color) return false;
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> visited(n,-1);
        for(int i=0;i<n;i++) {
            if(visited[i] == -1) {
                if(dfs(i,0,visited,adj) == false) return false;
            }
        }
        return true;
    }
};