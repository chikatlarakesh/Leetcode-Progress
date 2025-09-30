class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        using Node = pair<int,pair<int,int>>;
        priority_queue<Node,vector<Node>,greater<Node>> pq;
        pq.push({grid[0][0],{0,0}});

        vector<pair<int,int>> dir = {{0,-1},{-1,0},{0,1},{1,0}};
        while(!pq.empty()) {
            int time = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            if(row == n-1 && col == n-1) return time;

            for(auto &[r,c]: dir) {
                int i = row + r;
                int j = col + c;

                if(i>=0 && i<n && j>=0 && j<n) {
                    int maxCost = max(time, grid[i][j]);
                    if(maxCost < dist[i][j]) {
                        dist[i][j] = maxCost;
                        pq.push({maxCost,{i,j}});
                    }
                }
            }
        }
        return -1;
    }
};