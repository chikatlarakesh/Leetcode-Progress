class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        int m = numCourses;
        vector<vector<int>> adj(m);
        vector<int> inDegree(m,0);

        for(int i=0;i<n;i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[v].push_back(u);
            inDegree[u]++;
        }

        queue<int> q;
        vector<int> result;
        for(int i=0;i<m;i++) {
            if(inDegree[i] == 0) q.push(i);
        }

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            result.push_back(node);

            for(auto &it: adj[node]) {
                inDegree[it]--;
                if(inDegree[it] == 0) q.push(it);
            }
        }

        if(result.size() != m) return {};
        return result;
    }
};