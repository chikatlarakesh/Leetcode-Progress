class Solution {
public:
    bool dfs(int node,vector<int>& visited,vector<int>& pathVisited,vector<int>& isSafe,vector<vector<int>>& adj) {
        visited[node] = 1;
        pathVisited[node] = 1;

        for(auto &it: adj[node]) {
            if(!visited[it]) {
                if(dfs(it,visited,pathVisited,isSafe,adj) == true) return true;
            }
            else if(pathVisited[it]) return true;
        }

        isSafe[node] = 1;
        pathVisited[node] = 0;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> visited(n,0), pathVisited(n,0), isSafe(n,0);
        for(int i=0;i<n;i++) {
            if(!visited[i]) {
                dfs(i,visited,pathVisited,isSafe,adj);
            }
        }

        vector<int> safeNodes;
        for(int i=0;i<n;i++) {
            if(isSafe[i]) {
                safeNodes.push_back(i);
            }
        }
        return safeNodes;
    }
};