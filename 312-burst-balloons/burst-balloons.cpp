class Solution {
public:
    int maximumCoins(int i,int j,vector<int>& nums,vector<vector<int>> &dp) {
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int maxCoins = INT_MIN;
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
};