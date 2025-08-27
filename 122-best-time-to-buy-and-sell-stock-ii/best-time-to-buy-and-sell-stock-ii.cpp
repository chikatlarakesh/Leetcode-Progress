class Solution {
public:
    // int totalProfit(int i,int n,vector<int>& prices,int hasStock,vector<vector<int>>& dp)
    // {
    //     if(i==n) return 0;
    //     if(dp[i][hasStock]!=-1) return dp[i][hasStock];

    //     int buy=0,notBuy=0,sell=0,notSell=0;
    //     if(hasStock)
    //     {
    //         buy= -prices[i]+totalProfit(i+1,n,prices,0,dp);
    //         notBuy= totalProfit(i+1,n,prices,1,dp);
    //     }
    //     else
    //     {
    //         sell= prices[i]+totalProfit(i+1,n,prices,1,dp);
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

    // int maxProfit(vector<int>& prices) {
    //     int hasStock=1;
    //     int n=prices.size();
    //     vector<vector<int>> dp(n+1,vector<int>(2,0));

    //     for(int i=n;i>=0;i--)
    //     {
    //         for(int hasStock=0;hasStock<2;hasStock++)
    //         {
    //             if(i==n) dp[i][hasStock]=0;
    //             else
    //             {
    //                 int buy=0,notBuy=0,sell=0,notSell=0;
    //                 if(hasStock)
    //                 {
    //                     buy= -prices[i]+dp[i+1][0];
    //                     notBuy= dp[i+1][1];
    //                 }
    //                 else
    //                 {
    //                     sell= prices[i]+dp[i+1][1];
    //                     notSell= dp[i+1][0];
    //                 }
    //                 dp[i][hasStock]=max({buy,notBuy,sell,notSell});
    //             }
    //         }
    //     }
    //     return dp[0][1];
    // }

     int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int hasStock=1;
        vector<int> next(2,0),curr(2,0);

        for(int i=n;i>=0;i--)
        {
            for(int hasStock=0;hasStock<2;hasStock++)
            {
                if(i==n) curr[hasStock]=0;
                else
                {
                    int buy=0,notBuy=0,sell=0,notSell=0;
                    if(hasStock)
                    {
                        buy= -prices[i]+next[0];
                        notBuy= next[1];
                    }
                    else
                    {
                        sell= prices[i]+next[1];
                        notSell= next[0];
                    }
                    curr[hasStock]=max({buy,notBuy,sell,notSell});
                }
            }
            next=curr;
        }
        return curr[1];
    }
};