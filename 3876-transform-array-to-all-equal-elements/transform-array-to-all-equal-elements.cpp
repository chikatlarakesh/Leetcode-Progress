class Solution {
public:
    bool isPossible(vector<int> nums,int target, int k)
    {
        int n=nums.size();
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]!=target)
            {
                nums[i]*=-1;
                nums[i+1]*=-1;
                k--;
            }
            if(k<0) return false;
        }
        return nums[n-1]==target;
    }

    bool canMakeEqual(vector<int>& nums, int k) {
        return isPossible(nums,1,k) || isPossible(nums,-1,k);
    }
};