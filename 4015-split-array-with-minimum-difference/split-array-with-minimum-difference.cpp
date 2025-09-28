class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        long long sum = LLONG_MAX;
        vector<long long> prefix(n,0), incr(n,0), decr(n,0);
        incr[0] = 1;
        decr[n-1] = 1;

        long long prefixSum = 0;
        for(int i=0;i<n;i++) {
            prefixSum += nums[i];
            prefix[i] = prefixSum;
            if(i > 0) {
                if(incr[i-1] && nums[i] > nums[i-1]) incr[i] = 1;
            }
        }
        for(int i=n-2;i>=0;i--) {
            if(decr[i+1] && nums[i] > nums[i+1]) decr[i] = 1;
        }

        for(int i=0;i<n-1;i++) {
            if(incr[i] && decr[i+1]) {
                long long temp = llabs(prefix[i] - llabs((prefix[n-1] - prefix[i])));
                sum = min(temp,sum);
            }
        }
        if(sum == LLONG_MAX) return -1;
        return sum;
    }
};