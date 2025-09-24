class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> visited(n,vector<int>(n,0));

        q.push({{0,0},1});
        visited[0][0] = 1;
        vector<pair<int,int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

        while(!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dist = q.front().second;
            q.pop();
            if(row == n-1 && col == n-1) return dist;

            for(auto &[r,c]: dir) {
                int i = row + r;
                int j = col + c;
                int d = dist + 1;

                if(i>=0 && i<n && j>=0 && j<n && !visited[i][j] && grid[i][j] == 0) {
                    visited[i][j] = 1;
                    q.push({{i,j},d});
                }
            }
        }
        return -1;
    }
};