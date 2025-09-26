class Solution {
public:
    void dfs(int node,int dst,vector<int>& result,vector<vector<int>>& paths,vector<vector<int>>& adj) {
        result.push_back(node);
        if(node == dst) paths.push_back(result);

        for(auto &it: adj[node]) {
            dfs(it,dst,result,paths,adj);
        }
        result.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<vector<int>> paths;
        vector<int> result;
        dfs(0,n-1,result,paths,adj);
        return paths;

        // BFS
        // int n = adj.size();
        // queue<vector<int>> q;
        // vector<vector<int>> result;
        // q.push({0});

        // while(!q.empty()) {
        //     vector<int> path = q.front();
        //     int node = path.back();
        //     q.pop();
        //     if(node == n-1) result.push_back(path);

        //     for(auto &it: adj[node]) {
        //         vector<int> newPath = path;
        //         newPath.push_back(it);
        //         q.push(newPath);
        //     }
        // }
        // return result;
    }
};