class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(),nums.end());
        for(int num:nums)
        {
            if(original==num) original=original*2;
            if(num>original) break;
        }
        return original;
    }
};