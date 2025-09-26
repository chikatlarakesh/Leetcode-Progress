class Solution {
public:
    using Node = pair<int,int>;
    // DIJKSTRA 
    int dijkstra(int src,int n,vector<vector<pair<int,int>>>& adj,int k) {
        priority_queue<Node,vector<Node>,greater<Node>> pq;
        vector<int> distance(n,INT_MAX);

        pq.push({0,src});
        while(!pq.empty()) {
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(dist > distance[node]) continue;

            for(auto &it: adj[node]) {
                int adjNode = it.first;
                int adjDist = it.second;
                if(dist + adjDist < distance[adjNode]) {
                    distance[adjNode] = dist + adjDist;
                    pq.push({dist + adjDist,adjNode});
                }
            }
        }

        int count = 0;
        for(int i=0;i<n;i++) {
            if(i != src && distance[i] <= k) count++;
        }
        return count;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<Node>> adj(n);
        for(auto &edge:edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }

        int minCities = INT_MAX, city = 0;
        for(int i=0;i<n;i++) {
            int count = dijkstra(i,n,adj,distanceThreshold);
            if(count <= minCities) {
                minCities = count;
                city = i;
            }
        }
        return city;
    }


    // FLOYD - WARSHALL
    // int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    //     vector<vector<int>> dist(n,vector<int>(n,1e9));

    //     for(auto &edge:edges) {
    //         int u = edge[0];
    //         int v = edge[1];
    //         int wt = edge[2];
    //         dist[u][v] = wt;
    //         dist[v][u] = wt;
    //     }

    //     for(int i=0;i<n;i++) dist[i][i] = 0;

    //     for(int k=0;k<n;k++) {
    //         for(int i=0;i<n;i++) {
    //             for(int j=0;j<n;j++) {
    //                 dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    //             }
    //         }
    //     }

    //     int minCities = INT_MAX, city = 0;
    //     for(int i=0;i<n;i++) {
    //         int currCities = 0;
    //         for(int j=0;j<n;j++) {
    //             if(dist[i][j] != 0 && dist[i][j] <= distanceThreshold) currCities++;
    //         }
    //         if(currCities <= minCities) {
    //             minCities = currCities;
    //             city = i;
    //         }
    //     }
    //     return city;
    // }
};