class Solution {
public:
    // bool partitionArray(int i,int currSum,vector<int>& nums,vector<vector<int>>& dp)
    // {
    //     if(currSum==0) return true;
    //     if(i==0) return nums[i]==currSum;
    //     if(dp[i][currSum]!=-1) return dp[i][currSum];

    //     bool take=false;
    //     if(currSum>=nums[i]) take=partitionArray(i-1,currSum-nums[i],nums,dp);
    //     bool notTake=partitionArray(i-1,currSum,nums,dp);
    //     return dp[i][currSum]=(take || notTake);
    // }

    // bool canPartition(vector<int>& nums) {
    //     int n=nums.size();
    //     int totalSum=0;
    //     for(int num:nums) totalSum+=num;
    //     if(totalSum%2==1) return false;

    //     vector<vector<int>> dp(n,vector<int>((totalSum/2)+1,-1));
    //     return partitionArray(n-1,totalSum/2,nums,dp);
    // }

    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int totalSum=0;
        for(int num:nums) totalSum+=num;
        if(totalSum%2==1) return false;

        int size=max(nums[0],(totalSum/2)+1);
        vector<vector<bool>> dp(n,vector<bool>(size+1,false));
        
        for(int i=0;i<n;i++) dp[i][0]=true;
        dp[0][nums[0]]=true;

        for(int i=1;i<n;i++)
        {
            for(int currSum=1;currSum<=(totalSum/2);currSum++)
            {
                bool take=false;
                if(currSum>=nums[i]) take=dp[i-1][currSum-nums[i]];
                bool notTake=dp[i-1][currSum];
                dp[i][currSum]=(take || notTake);
            }
        }
        return dp[n-1][(totalSum/2)];
    }
};