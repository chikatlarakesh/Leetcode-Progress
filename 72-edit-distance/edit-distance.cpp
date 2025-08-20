class Solution {
public:
    int minOperations(int i,int j,string& s,string& t,vector<vector<int>>& dp)
    {
        if(j==-1) return i+1;
        if(i==-1) return j+1;
        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]==t[j]) return dp[i][j]=minOperations(i-1,j-1,s,t,dp);

        int Insert=1+minOperations(i,j-1,s,t,dp);
        int Delete=1+minOperations(i-1,j,s,t,dp);
        int Replace=1+minOperations(i-1,j-1,s,t,dp);
        return dp[i][j]=min({Insert,Delete,Replace});
    }

    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        vector<vector<int>> dp(n,vector<int>(m,-1));

        return minOperations(n-1,m-1,word1,word2,dp);
    }
};