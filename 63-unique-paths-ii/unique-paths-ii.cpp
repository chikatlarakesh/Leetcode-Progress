class Solution {
public:
    int possiblePaths(int i,int j,vector<vector<int>>& arr,vector<vector<int>>& dp)
    {
        if(i<0 || j<0 || arr[i][j]==1) return 0;
        if(i==0 && j==0) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int top=0,left=0;
        top=possiblePaths(i-1,j,arr,dp);
        left=possiblePaths(i,j-1,arr,dp);
        return dp[i][j]=top+left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        int n=arr.size();
        int m=arr[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return possiblePaths(n-1,m-1,arr,dp);
        // for(int i=0;i<n;i++) dp[i][0]=1;
        // for(int j=0;j<m;j++) dp[0][j]=1;

        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<m;j++)
        //     {
        //         if(arr[i][j]==1) dp[i][j]=0;
        //         else if(i==0 || j==0) dp[i][j]=1;
        //         else
        //         {
        //             int top=0,left=0;
        //             if(i>0) top=dp[i-1][j];
        //             if(j>0) left=dp[i][j-1];
        //             dp[i][j]=top+left;
        //         }
        //     }
        // }
        // return dp[n-1][m-1];
    }
};