class Solution {
public:
    int maxLength(int i,int prevInd,vector<int>& nums,vector<vector<int>>& dp)
    {
        if(i<0) return 0;
        if(dp[i][prevInd]!=-1) return dp[i][prevInd];

        int take=0,notTake=0;
        if(prevInd==nums.size() || nums[i]<nums[prevInd]) take= 1+maxLength(i-1,i,nums,dp);
        notTake= maxLength(i-1,prevInd,nums,dp);

        return dp[i][prevInd]=max(take,notTake);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return maxLength(n-1,n,nums,dp);
    }
};