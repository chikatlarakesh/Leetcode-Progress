class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n,1), suffix(n,1);

        for(int i=1;i<n;i++) {
            if(nums[i] > nums[i-1]) prefix[i] = prefix[i-1] + 1;
        }

        for(int i=n-2;i>=0;i--) {
            if(nums[i] < nums[i+1]) suffix[i] = suffix[i+1] + 1;
        }

        int maxValue = INT_MIN;
        for(int i=0;i<n-1;i++) {
            int k = min(prefix[i],suffix[i+1]);
            maxValue = max(maxValue,k);
        }
        return maxValue;
    }
};