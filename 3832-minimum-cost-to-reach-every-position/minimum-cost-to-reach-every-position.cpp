class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        int low=INT_MAX;
        int n=cost.size();
        int i;
        for(i=0;i<n;i++)
        {
            if(cost[i]<low)
            {
                low=cost[i];
            }
            cost[i]=low;
        }
        return cost;
    }
};