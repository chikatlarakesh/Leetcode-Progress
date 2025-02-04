class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int i,val=nums[0],temp=nums[0];
        int n=nums.size();
        for(i=1;i<n;i++)
        {
            if(nums[i]>nums[i-1])
            {
                temp=max(temp+nums[i],nums[i]);
            }
            else
            {
                temp=nums[i];
            }
            val=max(val,temp);
        }
        return val;
    }
};