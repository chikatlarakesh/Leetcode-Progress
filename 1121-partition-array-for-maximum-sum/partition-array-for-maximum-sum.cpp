class Solution {
public:
    // int maxSum(int i,int k,vector<int>& arr,vector<int>& dp) {
    //     int n = arr.size();
    //     if(i >= n) return 0;
    //     if(dp[i]!= -1) return dp[i];

    //     int maxi = 0, maxValue = 0;
    //     for(int j=i;j<n && j<i+k;j++) {
    //         maxValue = max(maxValue,arr[j]);
    //         int length = j - i + 1;
    //         int sum = (maxValue * length) + maxSum(j+1,k,arr,dp);
    //         maxi = max(sum,maxi);
    //     }
    //     return dp[i] = maxi;
    // }

    // int maxSumAfterPartitioning(vector<int>& arr, int k) {
    //     int n = arr.size();
    //     vector<int> dp(n,-1);
    //     return maxSum(0,k,arr,dp);
    // }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1,0);
        
        for(int i=n-1;i>=0;i--) {
            int maxi = 0, maxValue = 0;
            for(int j=i;j<n && j<i+k;j++) {
                maxValue = max(maxValue,arr[j]);
                int length = j - i + 1;
                int sum = (maxValue * length) + dp[j+1];
                maxi = max(sum,maxi);
            }
            dp[i] = maxi;
        }
        return dp[0];
    }
};