class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        using Node = pair<int,pair<int,int>> ;
        priority_queue<Node,vector<Node>,greater<Node>> pq;
        vector<vector<int>> visited(n,vector<int>(n,0));
        pq.push({grid[0][0],{0,0}});
        visited[0][0] = 1;

        vector<pair<int,int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        while(!pq.empty()) {
            int time = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            if(row == n-1 && col == n-1) return time;

            for(auto &[r,c]: dir) {
                int i = row + r;
                int j = col + c;

                if(i>=0 && i<n && j>=0 && j<n && !visited[i][j]) {
                    visited[i][j] = 1;
                    int currTime = max(time,grid[i][j]);
                    pq.push({currTime,{i,j}});
                }
            }
        }
        return -1;
    }
};