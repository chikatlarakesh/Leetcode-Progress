class Solution {
public:
    // int minCost(int i,int j,vector<vector<int>>& triangle,vector<vector<int>>& dp)
    // {
    //     if(i==triangle.size()-1) return triangle[i][j];
    //     if(dp[i][j]!=-1) return dp[i][j];

    //     int down=triangle[i][j]+minCost(i+1,j,triangle,dp);
    //     int diagonal=triangle[i][j]+minCost(i+1,j+1,triangle,dp);
    //     return dp[i][j]=min(down,diagonal);
    // }

    // int minimumTotal(vector<vector<int>>& triangle) {
    //     int n=triangle.size();
    //     vector<vector<int>> dp(n,vector<int>(n,-1));
    //     return minCost(0,0,triangle,dp);
    // }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        
        for(int i=n-1;i>=0;i--)
        {
            int m=triangle[i].size();
            for(int j=0;j<m;j++)
            {
                if(i==n-1) dp[i][j]=triangle[i][j];
                else
                {
                    int down=triangle[i][j]+dp[i+1][j];
                    int diagonal=triangle[i][j]+dp[i+1][j+1];
                    dp[i][j]=min(down,diagonal);
                }
            }
        }
        return dp[0][0];
    }
};