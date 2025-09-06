class Solution {
public:
    // MEMOIZATION
    //   int maxLength(int i,int prevInd,vector<int>& nums,vector<vector<int>>& dp)
    //     {
    //         if(i==0)
    //         {
    //             if(prevInd==nums.size() || nums[i]<nums[prevInd]) return 1;
    //             return 0;
    //         }
    //         if(dp[i][prevInd]!=-1) return dp[i][prevInd];
    
    //         int take=0,notTake=0;
    //         if(prevInd==nums.size() || nums[i]<nums[prevInd]) take= 1+maxLength(i-1,i,nums,dp);
    //         notTake= maxLength(i-1,prevInd,nums,dp);
    
    //         return dp[i][prevInd]=max(take,notTake);
    //     }

    // int lengthOfLIS(vector<int>& nums) {
    //     int n=nums.size();
    //     vector<vector<int>> dp(n,vector<int>(n+1,-1));
    //     return maxLength(n-1,n,nums,dp);
    // }

    // TABULATION
    // int lengthOfLIS(vector<int>& nums) {
    //     int n=nums.size();
    //     vector<vector<int>> dp(n,vector<int>(n+1,-1));
        
    //     for(int i=0;i<n;i++)
    //     {
    //         for(int prevInd=n;prevInd>=i;prevInd--)
    //         {
    //             if(i==0)
    //             {
    //                 if(prevInd==nums.size() || nums[i]<nums[prevInd]) dp[i][prevInd]= 1;
    //                 else dp[i][prevInd]= 0;
    //             }
    //             else
    //             {
    //                 int take=0,notTake=0;
    //                 if(prevInd==nums.size() || nums[i]<nums[prevInd]) take= 1+dp[i-1][i];
    //                 notTake= dp[i-1][prevInd];
            
    //                 dp[i][prevInd]=max(take,notTake);
    //             }
    //         }
    //     }
    //     return dp[n-1][n];
    // }

     // 2-D ARRAY SPACE OPTIMIZATION
    // int lengthOfLIS(vector<int>& nums) {
    //     int n=nums.size();
    //     vector<int> prev(n+1,-1),curr(n+1,-1);
        
    //     for(int i=0;i<n;i++)
    //     {
    //         for(int prevInd=n;prevInd>=i;prevInd--)
    //         {
    //             if(i==0)
    //             {
    //                 if(prevInd==nums.size() || nums[i]<nums[prevInd]) curr[prevInd]= 1;
    //                 else curr[prevInd]= 0;
    //             }
    //             else
    //             {
    //                 int take=0,notTake=0;
    //                 if(prevInd==nums.size() || nums[i]<nums[prevInd]) take= 1+prev[i];
    //                 notTake= prev[prevInd];
            
    //                 curr[prevInd]=max(take,notTake);
    //             }
    //         }
    //         prev=curr;
    //     }
    //     return prev[n];
    // }


    // 1-D ARRAY SPACE OPTIMIZATION
    // int lengthOfLIS(vector<int>& nums) {
    //     int n=nums.size();
    //     vector<int> prev(n+1,-1);
        
    //     for(int i=0;i<n;i++)
    //     {
    //         for(int prevInd=n;prevInd>=i;prevInd--)
    //         {
    //             if(i==0)
    //             {
    //                 if(prevInd==nums.size() || nums[i]<nums[prevInd]) prev[prevInd]= 1;
    //                 else prev[prevInd]= 0;
    //             }
    //             else
    //             {
    //                 int take=0,notTake=0;
    //                 if(prevInd==nums.size() || nums[i]<nums[prevInd]) take= 1+prev[i];
    //                 notTake= prev[prevInd];
            
    //                 prev[prevInd]=max(take,notTake);
    //             }
    //         }
    //     }
    //     return prev[n];
    // }

    // MOST OPTIMAL BUT DIFFERENT TABULATION
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        
        int maxi=1;
        for(int i=0;i<n;i++)
        {
            for(int prevInd=0;prevInd<i;prevInd++)
            {
                if(nums[prevInd]<nums[i])
                {
                    dp[i]=max(1+dp[prevInd],dp[i]);
                }
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};