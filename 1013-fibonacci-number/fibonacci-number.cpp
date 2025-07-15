class Solution {
public:
    int helper(int n,vector<int>& dp)
    {
        if(dp[n]!=-1) return dp[n];
        return dp[n]=helper(n-1,dp)+helper(n-2,dp);
    }

    int fib(int n) {
        if(n<=1) return n;
        vector<int> dp(n+1,-1);
        dp[0]=0;
        dp[1]=1;
        return helper(n,dp);
    }
};