class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();
        int prev = -1e9;
        for(int i=0;i<n;i++) {
            if(nums[i] == 1) {
                if(i - prev - 1 < k) return false;
                prev = i;
            }
        }
        return true;
    }
};