class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        using Node = pair<int,pair<int,int>>;
        queue<Node> q;
        if(src == dst) return 0;

        vector<vector<pair<int,int>>> adj(n);
        int m = flights.size();
        for(int i=0;i<m;i++) {
            int s = flights[i][0];
            int d = flights[i][1];
            int price = flights[i][2];
            adj[s].push_back({d,price});
        }

        vector<int> cheapest(n,INT_MAX);
        cheapest[src] = 0;
        q.push({0,{src,0}});
        while(!q.empty()) {
            int stops = q.front().first;
            int node = q.front().second.first;
            int currPrice = q.front().second.second;
            q.pop();
            if(stops > k) continue;

            for(auto &it: adj[node]) {
                int adjNode = it.first;
                int newPrice = it.second;
                int totalPrice = currPrice + newPrice;
                if(totalPrice < cheapest[adjNode] && stops <= k) {
                    cheapest[adjNode] = totalPrice;
                    q.push({stops+1,{adjNode,totalPrice}});
                }
            }
        }
        if(cheapest[dst] == INT_MAX) return -1;
        return cheapest[dst];
    }
};