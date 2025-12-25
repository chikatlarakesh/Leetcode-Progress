class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n = happiness.size();
        sort(happiness.rbegin(),happiness.rend());
        long long i=0,maxSum = 0, decr = 0;

        while(i < n && k > 0) {
            int val = happiness[i] - decr;
            if(val > 0) maxSum += val;
            else break;
            decr++;
            i++;
            k--;
        }
        return maxSum;

    }
};