class Solution {
public:
    // int maximumAmount(int i,int n,vector<int>& nums,vector<int>& dp)
    // {
    //     if(i<n) return 0;
    //     if(i==n) return nums[i];
    //     if(dp[i]!=-1) return dp[i];

    //     int take=nums[i]+maximumAmount(i-2,n,nums,dp);
    //     int notTake=maximumAmount(i-1,n,nums,dp);
    //     return dp[i]=max(take,notTake);
    // }

    // int rob(vector<int>& nums) {
    //     int n=nums.size();
    //     if(n==1) return nums[0];
    //     vector<int> dp1(n,-1);
    //     vector<int> dp2(n,-1);
    //     return max(maximumAmount(n-2,0,nums,dp1),maximumAmount(n-1,1,nums,dp2));
    // }


    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> dp1(n,-1);
        dp1[0]=nums[0];
        vector<int> dp2(n,-1);
        dp2[1]=nums[1];

        for(int i=1;i<=n-2;i++)
        {
            int take=nums[i];
            if(i>1) take+=dp1[i-2];
            int notTake=dp1[i-1];
            dp1[i]=max(take,notTake);
        }

        for(int i=2;i<=n-1;i++)
        {
            int take=nums[i];
            if(i>2) take+=dp2[i-2];
            int notTake=dp2[i-1];
            dp2[i]=max(take,notTake);
        }

        return max(dp1[n-2],dp2[n-1]);
    }
};