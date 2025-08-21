class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=prices[0],maxProfit=0;
        for(int num:prices)
        {
            maxProfit=max(maxProfit,num-buy);
            buy=min(buy,num);
        }
        return maxProfit;
    }
};