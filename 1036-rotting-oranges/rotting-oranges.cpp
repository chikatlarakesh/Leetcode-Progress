class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited = grid;
        // {{r,c},t}
        queue<pair<pair<int,int>,int>> q;
        int freshOranges = 0;

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j] == 2) {
                    q.push({{i,j},0});
                }
                else if(grid[i][j] == 1) freshOranges++;
            }
        }

        int maxTime = 0;
        vector<pair<int,int>> dir = {{-1,0},{0,1},{1,0},{0,-1}};
        while(!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            q.pop();
            maxTime = max(maxTime,time);

            for(auto [r,c]: dir) {
                int i = row + r;
                int j = col + c;

                if(i>=0 && i<n && j>=0 && j<m && visited[i][j]==1) {
                    freshOranges--;
                    visited[i][j] = 2;
                    q.push({{i,j},time+1});
                }
            }
        }

        if(freshOranges != 0) return -1;
        return maxTime;
    }
};