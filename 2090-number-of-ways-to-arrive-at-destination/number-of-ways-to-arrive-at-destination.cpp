class Solution {
public:
    const int MOD = 1000000007;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);

        int m = roads.size();
        for(int i=0;i<m;i++) {
            int src = roads[i][0];
            int dst = roads[i][1];
            int time = roads[i][2];

            adj[src].push_back({dst,time});
            adj[dst].push_back({src,time});
        }

        vector<long long> distance(n,LLONG_MAX), ways(n,0);
        using Node = pair<long long,int>;
        priority_queue<Node,vector<Node>,greater<Node>> pq;
        pq.push({0,0});
        distance[0] = 0;
        ways[0] = 1;

        while(!pq.empty()) {
            long long time = pq.top().first;
            long long node = pq.top().second;
            pq.pop();

            for(auto &it: adj[node]) {
                long long adjNode = it.first;
                long long adjTime = it.second;

                if(time + adjTime < distance[adjNode]) {
                    distance[adjNode] = time + adjTime;
                    pq.push({time + adjTime, adjNode});
                    ways[adjNode] = ways[node];
                }
                else if(time + adjTime == distance[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % MOD;
                }
            }
        }
        return ways[n-1] % MOD;
    }
};