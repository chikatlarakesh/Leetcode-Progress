class Solution {
public:
    // int maximumAmount(int i,vector<int>& nums,vector<int>& dp)
    // {
    //     if(i<0) return 0;
    //     if(i==0) return nums[0];
    //     if(dp[i]!=-1) return dp[i];

    //     int take=maximumAmount(i-2,nums,dp)+nums[i];
    //     int notTake=maximumAmount(i-1,nums,dp);
    //     return dp[i]=max(take,notTake);
    // }

    // int rob(vector<int>& nums) {
    //     int n=nums.size();
    //     vector<int> dp(n,-1);
    //     return maximumAmount(n-1,nums,dp);
    // }

    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> dp(n,-1);
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);

        for(int i=2;i<n;i++)
        {
            int take=dp[i-2]+nums[i];
            int notTake=dp[i-1];
            dp[i]=max(take,notTake);
        }
        return dp[n-1];
    }
};