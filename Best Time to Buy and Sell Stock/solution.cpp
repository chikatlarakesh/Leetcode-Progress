int maxProfit(vector<int>& prices) {
        int i,temp;
        int n=prices.size();
        int profit=0;
        int low=prices[0];
        for(i=1;i<n;i++)
        {
            temp=prices[i]-low;
            if(temp>profit)
            {
                profit=temp;
            }
            if(prices[i]<low)
            {
                low=prices[i];
            }
        }
        return profit;
    }
