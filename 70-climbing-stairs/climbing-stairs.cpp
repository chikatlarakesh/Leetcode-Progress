class Solution {
public:
    // int helper(int n,vector<int>& dp)
    // {
    //     if(dp[n]!=-1) return dp[n];
    //     return dp[n]=helper(n-1,dp)+helper(n-2,dp);
    // }

    int climbStairs(int n) {
        if(n==1) return 1;
        vector<int> dp(n+1,-1);
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;

        for(int i=3;i<=n;i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};