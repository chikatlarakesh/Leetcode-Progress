class Solution {
public:
    // BFS
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<vector<int>> adjRev(n);
        vector<int> inDegree(n,0);

        for(int i=0;i<n;i++) {
            for(auto &it: adj[i]) {
                adjRev[it].push_back(i);
                inDegree[i]++;
            }
        }

        queue<int> q;
        vector<int> safeNodes;
        for(int i=0;i<n;i++) {
            if(inDegree[i] == 0) q.push(i);
        }

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);

            for(auto &it: adjRev[node]) {
                inDegree[it]--;
                if(inDegree[it] == 0) q.push(it);
            }
        }

        sort(safeNodes.begin(),safeNodes.end());
        return safeNodes;
    }


    // DFS
    // bool dfs(int node,vector<int>& visited,vector<int>& pathVisited,vector<int>& isSafe,vector<vector<int>>& adj) {
    //     visited[node] = 1;
    //     pathVisited[node] = 1;

    //     for(auto &it: adj[node]) {
    //         if(!visited[it]) {
    //             if(dfs(it,visited,pathVisited,isSafe,adj) == true) return true;
    //         }
    //         else if(pathVisited[it]) return true;
    //     }

    //     isSafe[node] = 1;
    //     pathVisited[node] = 0;
    //     return false;
    // }

    // vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
    //     int n = adj.size();
    //     vector<int> visited(n,0), pathVisited(n,0), isSafe(n,0);
    //     for(int i=0;i<n;i++) {
    //         if(!visited[i]) {
    //             dfs(i,visited,pathVisited,isSafe,adj);
    //         }
    //     }

    //     vector<int> safeNodes;
    //     for(int i=0;i<n;i++) {
    //         if(isSafe[i]) {
    //             safeNodes.push_back(i);
    //         }
    //     }
    //     return safeNodes;
    // }

};