class Solution {
public:
    // int minSum(int i,int j,vector<vector<int>>& arr,int last,vector<vector<int>>& dp)
    // {
    //     if(j<0 || j>=arr.size() || j==last) return 1e9;
    //     if(i==arr.size()-1) return dp[i][j]=arr[i][j];
    //     if(dp[i][j]!=-1) return dp[i][j];

    //     int ans=INT_MAX;  
    //     for(int k=0;k<arr.size();k++)
    //     {
    //         ans=min(ans,arr[i][j]+minSum(i+1,k,arr,j,dp));
    //     }
    //     return dp[i][j]=ans;
    // }

    // int minFallingPathSum(vector<vector<int>>& grid) {
    //     int n=grid.size();
    //     int ans=INT_MAX;
    //     vector<vector<int>> dp(n,vector<int>(n,-1));
    //     for(int i=0;i<n;i++)
    //     {
    //         ans=min(ans,minSum(0,i,grid,n+1,dp));
    //     }
    //     return ans;
    // }

    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<n;j++)
            {
                int ans=INT_MAX;
                int last=j;
                if(i==n-1) dp[i][j]=grid[i][j];
                else
                {
                    for(int k=0;k<grid.size();k++)
                    {
                        if(k!=last) ans=min(ans,grid[i][j]+dp[i+1][k]);
                    }
                    dp[i][j]=ans;
                }
            }
        }
        
        int result=INT_MAX;
        for(int i=0;i<n;i++)
        {
            result=min(result,dp[0][i]);
        }
        return result;
    }
};