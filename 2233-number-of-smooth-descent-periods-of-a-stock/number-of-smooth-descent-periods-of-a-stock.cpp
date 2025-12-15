class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        vector<long long> prefix(n,1);

        long long periods = 1;
        for(int i=1;i<n;i++) {
            if(prices[i-1] - prices[i] == 1) {
                prefix[i] = prefix[i-1] + 1;
            }
            periods += prefix[i];
        }
        return periods;
    }
};