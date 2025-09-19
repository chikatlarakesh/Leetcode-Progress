class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        queue<pair<int,int>> q;

        for(int j=0;j<m;j++) {
            if(grid[0][j] == 1) {
                visited[0][j] = 1;
                q.push({0,j});
            }
            if(grid[n-1][j] == 1) {
                visited[n-1][j] = 1;
                q.push({n-1,j});
            }
        }

        for(int i=1;i<n-1;i++) {
            if(grid[i][0] == 1) {
                visited[i][0] = 1;
                q.push({i,0});
            }
            if(grid[i][m-1] == 1) {
                visited[i][m-1] = 1;
                q.push({i,m-1});
            }
        }

        vector<pair<int,int>> dir = {{-1,0},{0,1},{1,0},{0,-1}};
        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            grid[row][col] = -1;

            for(auto &[r,c]: dir) {
                int i = row + r;
                int j = col + c;

                if(i>=0 && i<n && j>=0 && j<m && !visited[i][j] && grid[i][j]==1) {
                    visited[i][j] = 1;
                    q.push({i,j});
                }
            }
        }

        int landCells = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j] == -1) grid[i][j] = 1;
                else if(grid[i][j] == 1) landCells++;
            }
        }
        return landCells;
    }

    // DFS APPROACH
    // void dfs(int row,int col,vector<vector<int>>& grid) {
    //     if(row<0 || row>=grid.size() || col<0 || col>=grid[0].size() || grid[row][col] != 1) return;

    //     grid[row][col] = -1;

    //     dfs(row+1,col,grid);
    //     dfs(row-1,col,grid);
    //     dfs(row,col+1,grid);
    //     dfs(row,col-1,grid);
    // }

    // int numEnclaves(vector<vector<int>>& grid) {
    //     int n = grid.size();
    //     int m = grid[0].size();

    //     for(int j=0;j<m;j++) {
    //         if(grid[0][j] == 1) {
    //             dfs(0,j,grid);
    //         }
    //         if(grid[n-1][j] == 1) {
    //             dfs(n-1,j,grid);
    //         }
    //     }

    //     for(int i=1;i<n-1;i++) {
    //         if(grid[i][0] == 1) {
    //             dfs(i,0,grid);
    //         }
    //         if(grid[i][m-1] == 1) {
    //             dfs(i,m-1,grid);
    //         }
    //     }

    //     int landCells = 0;
    //     for(int i=0;i<n;i++) {
    //         for(int j=0;j<m;j++) {
    //             if(grid[i][j] == -1) grid[i][j] = 1;
    //             else if(grid[i][j] == 1) landCells++;
    //         }
    //     }
    //     return landCells;
    // }
};