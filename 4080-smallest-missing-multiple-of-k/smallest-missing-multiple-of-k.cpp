class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int missing = k;
        for(int num : nums) {
            if(missing == num) missing += k;
        }
        return missing;
    }
};