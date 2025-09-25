class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        queue<pair<int,int>> q;
        vector<int> timeTaken(n+1,INT_MAX);

        vector<vector<pair<int,int>>> adj(n+1);
        int m = times.size();
        for(int i=0;i<m;i++) {
            int src = times[i][0];
            int dst = times[i][1];
            int signal = times[i][2];
            adj[src].push_back({dst,signal});
        }

        q.push({k,0});
        timeTaken[k] = 0;
        while(!q.empty()) {
            int node = q.front().first;
            int signal = q.front().second;
            q.pop();

            for(auto &it: adj[node]) {
                int adjNode = it.first;
                int adjSignal = it.second;

                if(signal + adjSignal < timeTaken[adjNode]) {
                    timeTaken[adjNode] = signal + adjSignal;
                    q.push({adjNode,signal + adjSignal});
                }
            }
        }

        int minTime = 0;
        for(int i=1;i<=n;i++) {
            if(timeTaken[i] == INT_MAX) return -1;
            minTime = max(minTime,timeTaken[i]);
        }
        return minTime;
    }
};