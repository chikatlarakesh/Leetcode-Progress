class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=INT_MAX,sell=INT_MIN;
        int maxProfit=0;
        for(int num:prices)
        {
            if(num<buy)
            {
                buy=sell=num;
            }
            else if(num>sell) sell=num;
            maxProfit=max(maxProfit,sell-buy);
        }
        return maxProfit;
    }
};