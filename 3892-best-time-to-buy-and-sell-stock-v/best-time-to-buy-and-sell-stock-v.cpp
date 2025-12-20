class Solution {
public:
    long long maxProfit(int i,int k,int CASE,int n,vector<int>& prices,vector<vector<vector<long long>>>& dp) {
        if(i == n) {
            if(CASE == 0) return 0;
            else return INT_MIN;
        }
        if(k == 0) return 0;
        if(dp[i][k][CASE] != -1) return dp[i][k][CASE];

        long long take = 0, notTake = 0;
        if(CASE == 1) {
            take = prices[i] + maxProfit(i+1,k-1,0,n,prices,dp);
        }
        else if(CASE == 2) {
            take = -prices[i] + maxProfit(i+1,k-1,0,n,prices,dp);
        }
        else {
            take = max((-prices[i] + maxProfit(i+1,k,1,n,prices,dp)),
                    (prices[i] + maxProfit(i+1,k,2,n,prices,dp)));
        }
        
        notTake = maxProfit(i+1,k,CASE,n,prices,dp);
        return dp[i][k][CASE] = max(take,notTake);
    }

    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        vector<vector<vector<long long>>> dp(n+1,vector<vector<long long>>(k+1,vector<long long>(3,-1)));
        return maxProfit(0,k,0,n,prices,dp);
    }
};