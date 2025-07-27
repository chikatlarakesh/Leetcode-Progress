class Solution {
public:
    // int maxCherries(int i,int j1,int j2,int n,int m,vector<vector<int>>& grid,vector<vector<vector<int>>>& dp)
    // {
    //     if(j1<0 || j1>=m || j2<0 || j2>=m) return -1e9;
    //     if(i==n-1)
    //     {
    //         if(j1==j2) return grid[i][j1];
    //         else
    //         {
    //             return grid[i][j1]+grid[i][j2];
    //         }
    //     }
    //     if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];

    //     int ans=INT_MIN;
    //     for(int x=-1;x<=1;x++)
    //     {
    //         for(int y=-1;y<=1;y++)
    //         {
    //             if(j1==j2) ans=max(ans,grid[i][j1]+maxCherries(i+1,j1+x,j2+y,n,m,grid,dp));
    //             else
    //             {
    //                 ans=max(ans,grid[i][j1]+grid[i][j2]+maxCherries(i+1,j1+x,j2+y,n,m,grid,dp));
    //             }
    //         }
    //     }
    //     return dp[i][j1][j2]=ans;
    // }

    // int cherryPickup(vector<vector<int>>& grid) {
    //     int n=grid.size();
    //     int m=grid[0].size();
    //     vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
    //     return maxCherries(0,0,m-1,n,m,grid,dp);
    // }

    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        for(int i=n-1;i>=0;i--)
        {
            for(int j1=0;j1<m;j1++)
            {
                for(int j2=0;j2<m;j2++)
                {
                    int ans=-1e9;
                    if(i==n-1)
                    {
                        if(j1==j2) dp[i][j1][j2]=grid[i][j1];
                        else dp[i][j1][j2]=grid[i][j1]+grid[i][j2];
                    }
                    else
                    {
                        for(int x=-1;x<=1;x++)
                        {
                            for(int y=-1;y<=1;y++)
                            {
                                if(j1+x>=0 && j1+x<m && j2+y>=0 && j2+y<m)
                                {
                                    if(j1==j2) ans=max(ans,grid[i][j1]+dp[i+1][j1+x][j2+x]);
                                    else
                                    {
                                        ans=max(ans,grid[i][j1]+grid[i][j2]+dp[i+1][j1+x][j2+y]);
                                    }
                                }
                            }
                        }
                        dp[i][j1][j2]=ans;
                    }
                }
            }
        }
        return dp[0][0][m-1];
    }
};