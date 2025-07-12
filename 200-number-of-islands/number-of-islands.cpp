class Solution {
public:
    void markAdjLands(int i,int j,int n,int m,vector<vector<char>>& grid)
    {
        if(grid[i][j]=='0') return;

        grid[i][j]='0';

        if(i+1<n) markAdjLands(i+1,j,n,m,grid);
        if(i-1>=0) markAdjLands(i-1,j,n,m,grid);
        if(j+1<m) markAdjLands(i,j+1,n,m,grid);
        if(j-1>=0) markAdjLands(i,j-1,n,m,grid);
    }

    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int totalIslands=0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                    totalIslands++;
                    markAdjLands(i,j,n,m,grid);
                }
            }
        }
        return totalIslands;
    }
};