class Solution {
public:
    // int maxLength(int i,int j,string& text1,string& text2,vector<vector<int>>& dp)
    // {
    //     if(i<0 || j<0) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];

    //     if(text1[i]==text2[j])
    //     {
    //         return 1+maxLength(i-1,j-1,text1,text2,dp);
    //     }
    //     return dp[i][j]=max(maxLength(i-1,j,text1,text2,dp),maxLength(i,j-1,text1,text2,dp));
    // }

    // int longestCommonSubsequence(string text1, string text2) {
    //     int n=text1.length();
    //     int m=text2.length();
    //     vector<vector<int>> dp(n,vector<int>(m,-1));
    //     return maxLength(n-1,m-1,text1,text2,dp);
    // }

    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length();
        int m=text2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0 || j==0) dp[i][j]=0;
                else
                {
                    if(text1[i-1]==text2[j-1])
                    {
                        dp[i][j]=1+dp[i-1][j-1];
                    }
                    else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};