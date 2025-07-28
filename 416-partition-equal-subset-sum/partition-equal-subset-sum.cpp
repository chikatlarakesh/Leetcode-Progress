class Solution {
public:
    bool partitionArray(int i,int currSum,vector<int>& nums,vector<vector<int>>& dp)
    {
        if(currSum==0) return true;
        if(i==0) return nums[i]==currSum;
        if(dp[i][currSum]!=-1) return dp[i][currSum];

        bool take=false;
        if(currSum>=nums[i]) take=partitionArray(i-1,currSum-nums[i],nums,dp);
        bool notTake=partitionArray(i-1,currSum,nums,dp);
        return dp[i][currSum]=(take || notTake);
    }

    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int totalSum=0;
        for(int num:nums) totalSum+=num;
        if(totalSum%2==1) return false;

        vector<vector<int>> dp(n,vector<int>((totalSum/2)+1,-1));
        return partitionArray(n-1,totalSum/2,nums,dp);
    }
};