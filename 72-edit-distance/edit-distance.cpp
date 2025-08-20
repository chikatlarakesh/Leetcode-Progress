class Solution {
public:
    //
    // int minOperations(int i,int j,string& s,string& t,vector<vector<int>>& dp)
    // {
    //     if(j==-1) return i+1;
    //     if(i==-1) return j+1;
    //     if(dp[i][j]!=-1) return dp[i][j];

    //     if(s[i]==t[j]) return dp[i][j]=minOperations(i-1,j-1,s,t,dp);

    //     int Insert=1+minOperations(i,j-1,s,t,dp);
    //     int Delete=1+minOperations(i-1,j,s,t,dp);
    //     int Replace=1+minOperations(i-1,j-1,s,t,dp);
    //     return dp[i][j]=min({Insert,Delete,Replace});
    // }

    // int minDistance(string word1, string word2) {
    //     int n=word1.length();
    //     int m=word2.length();
    //     vector<vector<int>> dp(n,vector<int>(m,-1));

    //     return minOperations(n-1,m-1,word1,word2,dp);
    // }

    int minDistance(string s, string t) {
        int n=s.length();
        int m=t.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));

        for(int i=0;i<=n;i++) dp[i][0]=i;
        for(int j=0;j<=m;j++) dp[0][j]=j;

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==t[j-1]) dp[i][j]=dp[i-1][j-1];
                else
                {
                    int Insert=1+dp[i][j-1];
                    int Delete=1+dp[i-1][j];
                    int Replace=1+dp[i-1][j-1];
                    dp[i][j]=min({Insert,Delete,Replace});
                }
            }
        }
        return dp[n][m];
    }
};