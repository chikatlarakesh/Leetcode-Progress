class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& adj) {
        int n = adj.size();
        queue<vector<int>> q;
        vector<vector<int>> result;
        q.push({0});

        while(!q.empty()) {
            vector<int> path = q.front();
            int node = path.back();
            q.pop();
            if(node == n-1) result.push_back(path);

            for(auto &it: adj[node]) {
                vector<int> newPath = path;
                newPath.push_back(it);
                q.push(newPath);
            }
        }
        return result;
    }
};