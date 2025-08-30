class Solution {
public:
    const int MOD= 1000000007;
    int countWays(int i,int j,int n,int m,vector<vector<int>>& grid,int dir,vector<vector<vector<int>>>& dp)
    {
        if(i>=n || j>=m) return 0;
        if(i==n-1 && j==m-1) return 1;
        if(dp[i][j][dir]!=-1) return dp[i][j][dir];

        if(grid[i][j]==1)
        {
            if(dir==1) return dp[i][j][dir]=countWays(i+1,j,n,m,grid,2,dp)%MOD;
            else if(dir==2) return dp[i][j][dir]=countWays(i,j+1,n,m,grid,1,dp)%MOD;
        }

        int right=countWays(i,j+1,n,m,grid,1,dp)%MOD;
        int down=countWays(i+1,j,n,m,grid,2,dp)%MOD;
        return dp[i][j][dir]=(right+down)%MOD;
    }

    
    int uniquePaths(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(3,-1)));
        return countWays(0,0,n,m,grid,0,dp)%MOD;
    }
};