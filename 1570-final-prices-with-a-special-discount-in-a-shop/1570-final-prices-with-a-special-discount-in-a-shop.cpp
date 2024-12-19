class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector <int> result;
        int n=prices.size();
        int i,j,count;
        for(i=0;i<n;i++)
        {
            count=0;
            for(j=i+1;j<n;j++)
            {
                if(prices[j]<=prices[i])
                {
                    int val=prices[i]-prices[j];
                    result.push_back(val);
                    count++;
                    break;
                }
            }
            if(count==0)
            {
                result.push_back(prices[i]);
            }
        }
        return result;
    }
};