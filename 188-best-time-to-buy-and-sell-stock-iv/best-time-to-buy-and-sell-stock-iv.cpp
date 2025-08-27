class Solution {
public:

    // MEMOIZATION
    // int totalProfit(int i,int hasStock,int count,int n,vector<int>& nums,vector<vector<vector<int>>>& dp)
    // {
    //     if(i==n || count==0) return 0;
    //     if(dp[i][hasStock][count]!=-1) return dp[i][hasStock][count];

    //     int buy=0,notBuy=0,sell=0,notSell=0;
    //     if(hasStock)
    //     {
    //         buy= -nums[i]+totalProfit(i+1,0,count,n,nums,dp);
    //         notBuy= totalProfit(i+1,hasStock,count,n,nums,dp);
    //     }
    //     else
    //     {
    //         sell= nums[i]+totalProfit(i+1,1,count-1,n,nums,dp);
    //         notSell= totalProfit(i+1,hasStock,count,n,nums,dp);
    //     }

    //     return dp[i][hasStock][count]=max({buy,notBuy,sell,notSell});
    // }

    // int maxProfit(int k,vector<int>& prices) {
    //     int n=prices.size();
    //     int hasStock=1; // 1 -> empty
    //     vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
    //     return totalProfit(0,hasStock,k,n,prices,dp);
    // }



    // TABULATION
    // int maxProfit(int k,vector<int>& prices) {
    //     int n=prices.size();
    //     int hasStock=1; // 1 -> empty
    //     vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
        
    //     for(int i=n;i>=0;i--)
    //     {
    //         for(int hasStock=0;hasStock<2;hasStock++)
    //         {
    //             for(int count=0;count<k+1;count++)
    //             {
    //                 if(i==n || count==0) dp[i][hasStock][count]=0;
    //                 else
    //                 {
    //                     int buy=0,notBuy=0,sell=0,notSell=0;
    //                     if(hasStock)
    //                     {
    //                         buy= -prices[i]+dp[i+1][0][count];
    //                         notBuy= dp[i+1][hasStock][count];
    //                     }
    //                     else
    //                     {
    //                         sell= prices[i]+dp[i+1][1][count-1];
    //                         notSell= dp[i+1][hasStock][count];
    //                     }
    //                     dp[i][hasStock][count]=max({buy,notBuy,sell,notSell});
    //                 }
    //             }
    //         }
    //     }
    //     return dp[0][1][k];
    // }



    // SPACE OPTIMIZATION
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        int hasStock=1; // 1 -> empty
        //vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        vector<vector<int>> next(2,vector<int>(k+1,-1)), curr(2,vector<int>(k+1,-1));
        
        for(int i=n;i>=0;i--)
        {
            for(int hasStock=0;hasStock<2;hasStock++)
            {
                for(int count=0;count<k+1;count++)
                {
                    if(i==n || count==0) curr[hasStock][count]=0;
                    else
                    {
                        int buy=0,notBuy=0,sell=0,notSell=0;
                        if(hasStock)
                        {
                            buy= -prices[i]+next[0][count];
                            notBuy= next[hasStock][count];
                        }
                        else
                        {
                            sell= prices[i]+next[1][count-1];
                            notSell= next[hasStock][count];
                        }
                        curr[hasStock][count]=max({buy,notBuy,sell,notSell});
                    }
                }
            }
            next=curr;
        }
        return curr[1][k];
    }
};