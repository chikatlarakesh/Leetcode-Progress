class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> suffix(n,1);

        for(int i=n-2;i>=0;i--) {
            if(nums[i] < nums[i+1]) suffix[i] = suffix[i+1] + 1;
        }

        int prefix = 1,maxValue = INT_MIN;
        for(int i=0;i<n-1;i++) {
            if(i>0 && nums[i] > nums[i-1]) prefix++;
            else prefix = 1;

            int k = min(prefix,suffix[i+1]);
            maxValue = max(maxValue,k);
        }
        return maxValue;
    }
};