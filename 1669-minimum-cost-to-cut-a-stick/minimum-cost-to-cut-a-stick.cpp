class Solution {
public:
    int mcm(int i,int j,vector<int>& nums,vector<vector<int>>& dp) {
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int minCost = INT_MAX;
        for(int k=i;k<=j;k++) {
            int cost = (nums[j+1] - nums[i-1]) + mcm(i,k-1,nums,dp) + mcm(k+1,j,nums,dp);
            minCost = min(minCost,cost);
        }
        return dp[i][j] = minCost;
    }

    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        int m = cuts.size();
        vector<vector<int>> dp(m,vector<int>(m,-1));
        return mcm(1,m-2,cuts,dp);
    }
};