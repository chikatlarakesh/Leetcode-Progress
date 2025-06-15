class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());
        int largest=nums[0];
        int secLargest=nums[1];
        int result=(largest-1)*(secLargest-1);
        return result;
    }
};