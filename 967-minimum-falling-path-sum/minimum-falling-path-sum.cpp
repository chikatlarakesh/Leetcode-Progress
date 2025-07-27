class Solution {
public:
    // int minCost(int i,int j,vector<vector<int>>& arr,vector<vector<int>>& dp)
    // {
    //     if(j<0 || j>=arr.size()) return 1e9;
    //     if(i==arr.size()-1) return dp[i][j]=arr[i][j];
    //     if(dp[i][j]!=-1) return dp[i][j];

    //     int LDiagonal=arr[i][j]+minCost(i+1,j-1,arr,dp);
    //     int down=arr[i][j]+minCost(i+1,j,arr,dp);
    //     int RDiagonal=arr[i][j]+minCost(i+1,j+1,arr,dp);
    //     return dp[i][j]=min({LDiagonal,down,RDiagonal});
    // }

    // int minFallingPathSum(vector<vector<int>>& matrix) {
    //     int n=matrix.size();
    //     int ans=INT_MAX;
    //     vector<vector<int>> dp(n,vector<int>(n,-1));
    //     for(int i=0;i<n;i++)
    //     {
    //         ans=min(ans,minCost(0,i,matrix,dp));
    //     }
    //     return ans;
    // }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int ans=INT_MAX;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<n;j++)
            {
                if(i==n-1) dp[i][j]=matrix[i][j];
                else
                {
                    int LDiagonal=1e9,RDiagonal=1e9;
                    if(j>0) LDiagonal=matrix[i][j]+dp[i+1][j-1];
                    int down=matrix[i][j]+dp[i+1][j];
                    if(j<n-1) RDiagonal=matrix[i][j]+dp[i+1][j+1];
                    dp[i][j]=min({LDiagonal,down,RDiagonal});
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            ans=min(ans,dp[0][i]);
        }
        return ans;
    }
};