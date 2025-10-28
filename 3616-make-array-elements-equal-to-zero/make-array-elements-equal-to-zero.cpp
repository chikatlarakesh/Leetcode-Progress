class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int zeroCount = 0;
        vector<int> prefix(n);
        prefix[0] = nums[0];
        if(nums[0] == 0) zeroCount++;
        for(int i=1;i<n;i++) {
            prefix[i] = prefix[i-1] + nums[i];
            if(nums[i] == 0) zeroCount++;
        }
        if(zeroCount == n) return 2 * n;

        int count = 0;
        for(int i=0;i<n;i++) {
            if(nums[i] == 0) {
                int left = 0;
                if(i > 0) left = prefix[i-1];
                int right = prefix[n-1] - prefix[i];

                if(left == right) count += 2;
                else if(abs(left - right) <= 1) count++;
            }
        }
        return count;
    }
};