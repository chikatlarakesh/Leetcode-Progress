class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int i=0;
        int result,result1;
        result=nums[0]*nums[1]*nums[n-1];
        result1=nums[n-1]*nums[n-2]*nums[n-3];
        if(result>result1)
        {
            return result;
        }
        else
        {
            return result1;
        }
    }
};