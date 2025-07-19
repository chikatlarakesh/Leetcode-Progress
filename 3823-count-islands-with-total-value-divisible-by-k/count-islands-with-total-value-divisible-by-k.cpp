class Solution {
public:
    long long dfs(int row,int col,vector<vector<int>>& grid)
    {
        if(row<0 || row>=grid.size() || col<0 || col>=grid[0].size()) return 0;
        if(grid[row][col]==0) return 0;

        long long currVal=grid[row][col];
        grid[row][col]=0;

        long long maxValue=dfs(row+1,col,grid)+ dfs(row-1,col,grid)+dfs(row,col+1,grid)+ dfs(row,col-1,grid);

        return currVal+maxValue;
    }
    
    int countIslands(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        int totalIslands=0;
        for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                    {
                        if(grid[i][j]!=0)
                        {
                            long long sum=dfs(i,j,grid);
                            if(sum%k==0) totalIslands++;
                        }
                    }
            }
        return totalIslands;
    }
};