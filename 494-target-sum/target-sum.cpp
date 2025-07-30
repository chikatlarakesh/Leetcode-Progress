class Solution {
public:
    int targetSum(int i,int sum,vector<int>& nums,int target)
    {
        if(i==0)
        {
            int add=sum+nums[i];
            int subtract=sum-nums[i];
            if(add==target && subtract==target) return 2;
            if(add==target || subtract==target) return 1;
            return 0;
        }

        int add=targetSum(i-1,sum+nums[i],nums,target);
        int subtract=targetSum(i-1,sum-nums[i],nums,target);
        return add+subtract;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        return targetSum(n-1,0,nums,target);
    }
};