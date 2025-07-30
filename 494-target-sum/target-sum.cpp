class Solution {
public:
//     int partitionArray(int i,int target,vector<int>& arr,vector<vector<int>>& dp)
//   {
//       if(i==0)
//       {
//           if(target==0 && arr[i]==0) return 2;
//           if(target==0 || target==arr[i]) return 1;
//           return 0;
//       }
//       if(dp[i][target]!=-1) return dp[i][target];
      
//       int take=0;
//       if(target>=arr[i]) take=partitionArray(i-1,target-arr[i],arr,dp);
//       int notTake=partitionArray(i-1,target,arr,dp);
//       return dp[i][target]=take+notTake;
//   }
  
    int countPartitions(vector<int>& arr, int d) {
        int n=arr.size();
        int sum=accumulate(arr.begin(),arr.end(),0);
        if((d+sum)%2==1 || (d+sum)<0) return 0;
        int target=(d+sum)/2;
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        //if(target%2==1) return 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=target;j++)
            {
                if(i==0)
                {
                    if(j==0 && arr[i]==0) dp[i][j]=2;
                    else if(j==0 || j==arr[i]) dp[i][j]=1;
                    else dp[i][j]=0;
                }
                else
                {
                     int take=0;
                      if(j>=arr[i]) take=dp[i-1][j-arr[i]];
                      int notTake=dp[i-1][j];
                      dp[i][j]=take+notTake;
                }
            }
        }
        return dp[n-1][target];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return countPartitions(nums,target);
    }
};