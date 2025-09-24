class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        using node = pair<pair<int,int>,int>;
        priority_queue<node,vector<node>,greater<node>> pq;
        vector<vector<int>> effort(n,vector<int>(m,INT_MAX));

        pq.push({{0,0},0});
        effort[0][0] = 0;
        vector<pair<int,int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while(!pq.empty()) {
            int row = pq.top().first.first;
            int col = pq.top().first.second;
            int currEffort = pq.top().second;
            pq.pop();
            if(row == n-1 && col == m-1) return currEffort;
            if(currEffort > effort[row][col]) continue;

            for(auto &[r,c]: dir) {
                int i = row + r;
                int j = col + c;

                if(i>=0 && i<n && j>=0 && j<m) {
                    int e = max(currEffort,abs(heights[row][col] - heights[i][j]));
                    if(e < effort[i][j]) {
                        effort[i][j] = e;
                        pq.push({{i,j},e});
                    }
                }
            }
        }   
        return effort[n-1][m-1];
    }
};