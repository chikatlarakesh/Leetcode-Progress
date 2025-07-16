class Solution {
public:
    int backtrack(int i,vector<int>& cost,vector<int>& dp)
    {
        if(i>=cost.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int left=cost[i]+backtrack(i+1,cost,dp);
        int right=cost[i]+backtrack(i+2,cost,dp);
        return dp[i]=min(left,right);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(),-1);
        int first=backtrack(0,cost,dp);
        int second=backtrack(1,cost,dp);
        return min(first,second);
    }
};