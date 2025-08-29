class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int lb=max_element(nums.begin(),nums.end()) - nums.begin();
        return lb;
    }
};