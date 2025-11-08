class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n,1), right(n,1);

        int maxLength = 1;
        for(int i=1;i<n;i++) {
            if(nums[i] >= nums[i-1]) left[i] = left[i-1] + 1;
            maxLength = max(maxLength, left[i]);
        }

        for(int i=n-2;i>=0;i--) {
            if(nums[i] <= nums[i+1]) right[i] = right[i+1] + 1;
        }

        for(int i=0;i<n;i++) {
            int l = 0, r = 0;
            if(i > 0) l = left[i-1];
            if(i < n - 1) r = right[i+1];

            if(i > 0 && i+1 < n && nums[i-1] <= nums[i+1]) {
                maxLength = max(maxLength, l + r + 1);
            }

            maxLength = max(maxLength, l+1);
            maxLength = max(maxLength, r+1);
        }
        return maxLength;
    }
};