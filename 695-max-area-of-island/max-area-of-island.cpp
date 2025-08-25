class Solution {
public:
    int dfs(int i,int j,vector<vector<int>>& grid)
    {
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]==0) return 0;

        grid[i][j]=0;

        int left=dfs(i,j-1,grid);
        int right=dfs(i,j+1,grid);
        int top=dfs(i-1,j,grid);
        int down=dfs(i+1,j,grid);

        return 1+(left+right+top+down);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int maxArea=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    maxArea=max(maxArea,dfs(i,j,grid));
                }
            }
        }
        return maxArea;
    }
};