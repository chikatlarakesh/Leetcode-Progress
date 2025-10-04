class Solution {
public:
    int mcm(int i,int j,int start,int end,vector<int>& nums,vector<vector<int>>& dp) {
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int minCost = INT_MAX;
        for(int k=i;k<=j;k++) {
            int leftCost = mcm(i,k-1,start,nums[k],nums,dp);
            int rightCost = mcm(k+1,j,nums[k],end,nums,dp);
            int cost = (end - start) + leftCost + rightCost;
            minCost = min(minCost,cost);
        }
        return dp[i][j] = minCost;
    }

    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        int m = cuts.size();
        vector<vector<int>> dp(m,vector<int>(m,-1));
        return mcm(0,m-1,0,n,cuts,dp);
    }
};