class Solution {
public:
    int coinChange(int i,int amount,vector<int>& coins,vector<vector<int>>& dp)
    {
        if(i==0)
        {
            if(amount==0) return 1;
            if(amount%coins[i]==0) return 1;
            return 0;
        }
        if(dp[i][amount]!=-1) return dp[i][amount];

        int take=0;
        if(amount>=coins[i]) take=coinChange(i,amount-coins[i],coins,dp);
        int notTake=coinChange(i-1,amount,coins,dp);
        return dp[i][amount]=take+notTake;
    }

    int change(int amount, vector<int>& coins) {
        if(amount==0) return 1;
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return coinChange(n-1,amount,coins,dp);
    }
};