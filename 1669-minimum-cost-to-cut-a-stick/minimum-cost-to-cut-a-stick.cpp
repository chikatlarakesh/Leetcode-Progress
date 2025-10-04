class Solution {
public:
    int mcm(int i,int j,vector<int>& nums,vector<vector<int>>& dp) {
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int minCost = INT_MAX;
        for(int k=i;k<=j;k++) {
            int leftCost = mcm(i,k-1,nums,dp);
            int rightCost = mcm(k+1,j,nums,dp);
            int cost = (nums[j+1] - nums[i-1]) + leftCost + rightCost;
            minCost = min(minCost,cost);
        }
        return dp[i][j] = minCost;
    }

    int minCost(int n, vector<int>& nums) {
        nums.push_back(n);
        nums.insert(nums.begin(),0);
        sort(nums.begin(),nums.end());
        int m = nums.size();
        vector<vector<int>> dp(m,vector<int>(m,0));
        //return mcm(1,m-2,cuts,dp);

        for(int i=m-2;i>=1;i--) {
            for(int j=i;j<m-1;j++) {
                int minCost = INT_MAX;
                for(int k=i;k<=j;k++) {
                    int leftCost = dp[i][k-1];
                    int rightCost = dp[k+1][j];
                    int cost = (nums[j+1] - nums[i-1]) + leftCost + rightCost;
                    minCost = min(minCost,cost);
                }
                dp[i][j] = minCost;
            }
        }
        return dp[1][m-2];
    }
};