class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int>>,greater<pair<pair<int,int>,int>>> pq;
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> effort(n,vector<int>(m,INT_MAX));

        pq.push({{0,0},0});
        effort[0][0] = 0;
        vector<pair<int,int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while(!pq.empty()) {
            int row = pq.top().first.first;
            int col = pq.top().first.second;
            int currEffort = pq.top().second;
            pq.pop();

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