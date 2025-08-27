class Solution {
public:
    // MEMOIZATION
    // int totalProfit(int i,int n,vector<int>& prices,int hasStock,vector<vector<int>>& dp)
    // {
    //     if(i>=n) return 0;
    //     if(dp[i][hasStock]!=-1) return dp[i][hasStock];

    //     int buy=0,notBuy=0,sell=0,notSell=0;
    //     if(hasStock)
    //     {
    //         buy= -prices[i]+totalProfit(i+1,n,prices,0,dp);
    //         notBuy= totalProfit(i+1,n,prices,1,dp);
    //     }
    //     else
    //     {
    //         sell= prices[i]+totalProfit(i+2,n,prices,1,dp);
    //         notSell= totalProfit(i+1,n,prices,0,dp);
    //     }
    //     return dp[i][hasStock]=max({buy,notBuy,sell,notSell});
    // }


    // int maxProfit(vector<int>& prices) {
    //     int hasStock=1;
    //     int n=prices.size();
    //     vector<vector<int>> dp(n,vector<int>(2,-1));
    //     return totalProfit(0,n,prices,hasStock,dp);
    // }

    int maxProfit(vector<int>& prices) {
        int hasStock=1;
        int n=prices.size();
        vector<vector<int>> dp(n+2,vector<int>(2,0));
        
        for(int i=n-1;i>=0;i--)
        {
            for(int hasStock=0;hasStock<2;hasStock++)
            {
                int buy=0,notBuy=0,sell=0,notSell=0;
                if(hasStock)
                {
                    buy= -prices[i]+dp[i+1][0];
                    notBuy= dp[i+1][1];
                }
                else
                {
                    sell= prices[i]+dp[i+2][1];
                    notSell= dp[i+1][0];
                }
                dp[i][hasStock]=max({buy,notBuy,sell,notSell});
            }
        }
        return dp[0][1];
    }
};