class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length();
        int m=text2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        
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

    int minInsertions(string s) {
        int n=s.length();
        string reversed=s;
        reverse(reversed.begin(),reversed.end());
        int maxLength=longestCommonSubsequence(s,reversed);
        int minInsertions=n-maxLength;
        return minInsertions;
    }
};