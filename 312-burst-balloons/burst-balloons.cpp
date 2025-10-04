class Solution {
public:
    // MEMOIZATION
    int maximumCoins(int i,int j,vector<int>& nums,vector<vector<int>> &dp) {
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int maxCoins = 0;
        for(int k=i;k<=j;k++) {
            int left = maximumCoins(i,k-1,nums,dp);
            int right = maximumCoins(k+1,j,nums,dp);
            int coins = (nums[i - 1] * nums[k] * nums[j + 1]) + left + right;
            maxCoins = max(maxCoins,coins);
        }
        return dp[i][j] = maxCoins;
    }

    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return maximumCoins(1,n-2,nums,dp);
    }


    // TABULATION
    // int maxCoins(vector<int>& nums) {
    //     nums.insert(nums.begin(),1);
    //     nums.push_back(1);
    //     int n = nums.size();
    //     vector<vector<int>> dp(n,vector<int>(n,0));
        
    //     for(int i=n-2;i>=1;i--) {
    //         for(int j=1;j<=n-2;j++) {
    //             int maxCoins = 0;
    //             for(int k=i;k<=j;k++) {
    //                 int left = dp[i][k-1];
    //                 int right = dp[k+1][j];
    //                 int coins = (nums[i - 1] * nums[k] * nums[j + 1]) + left + right;
    //                 maxCoins = max(maxCoins,coins);
    //             }
    //             dp[i][j] = maxCoins;
    //         }
    //     }
    //     return dp[1][n-2];
    //}
};