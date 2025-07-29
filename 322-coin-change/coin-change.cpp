class Solution {
public:
    // long long minCoins(int i,int amount,vector<int>& coins,vector<vector<long long>>& dp)
    // {
    //     if(i==0)
    //     {
    //         if(amount%coins[i]==0) return amount/coins[i];
    //         return INT_MAX;
    //     }
    //     if(dp[i][amount]!=-1) return dp[i][amount];

    //     long long take=INT_MAX;
    //     if(amount>=coins[i]) take=1+minCoins(i,amount-coins[i],coins,dp);
    //     long long notTake=minCoins(i-1,amount,coins,dp);
    //     return dp[i][amount]=min(take,notTake);
    // }

    // int coinChange(vector<int>& coins, int amount) {
    //     if(amount==0) return 0;
    //     int n=coins.size();
    //     vector<vector<long long>> dp(n,vector<long long>(amount+1,-1));
    //     long long totalCoins=minCoins(n-1,amount,coins,dp);
    //     if(totalCoins>=INT_MAX) return -1;
    //     return (int)totalCoins;
    // }

    // int coinChange(vector<int>& coins, int total) {
    //     if(total==0) return 0;
    //     int n=coins.size();
    //     vector<vector<long long>> dp(n,vector<long long>(total+1,-1));
        
    //     for(int i=0;i<n;i++)
    //     {
    //         for(int amount=0;amount<=total;amount++)
    //         {
    //             if(i==0)
    //             {
    //                 if(amount%coins[i]==0) dp[i][amount]=amount/coins[i];
    //                 else dp[i][amount]=INT_MAX;
    //             }
    //             else
    //             {
    //                 long long take=INT_MAX;
    //                 if(amount>=coins[i]) take=1+dp[i][amount-coins[i]];
    //                 long long notTake=dp[i-1][amount];
    //                 dp[i][amount]=min(take,notTake);
    //             }
    //         }
    //     }
    //     if(dp[n-1][total]==INT_MAX) return -1;
    //     else return dp[n-1][total];
    // }

    int coinChange(vector<int>& coins, int total) {
        if(total==0) return 0;
        int n=coins.size();
        vector<long long> prev(total+1,-1);
        
        for(int i=0;i<n;i++)
        {
            for(int amount=0;amount<=total;amount++)
            {
                if(i==0)
                {
                    if(amount%coins[i]==0) prev[amount]=amount/coins[i];
                    else prev[amount]=INT_MAX;
                }
                else
                {
                    long long take=INT_MAX;
                    if(amount>=coins[i]) take=1+prev[amount-coins[i]];
                    long long notTake=prev[amount];
                    prev[amount]=min(take,notTake);
                }
            }
        }
        if(prev[total]==INT_MAX) return -1;
        else return prev[total];
    }
};