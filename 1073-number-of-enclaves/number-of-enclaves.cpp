class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>& grid) {
        if(row<0 || row>=grid.size() || col<0 || col>=grid[0].size() || grid[row][col] != 1) return;

        grid[row][col] = -1;

        dfs(row+1,col,grid);
        dfs(row-1,col,grid);
        dfs(row,col+1,grid);
        dfs(row,col-1,grid);
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        for(int j=0;j<m;j++) {
            if(grid[0][j] == 1) {
                dfs(0,j,grid);
            }
            if(grid[n-1][j] == 1) {
                dfs(n-1,j,grid);
            }
        }

        for(int i=1;i<n-1;i++) {
            if(grid[i][0] == 1) {
                dfs(i,0,grid);
            }
            if(grid[i][m-1] == 1) {
                dfs(i,m-1,grid);
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
};