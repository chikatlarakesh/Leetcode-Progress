class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0,sum=0,mini=INT_MAX;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            if(k>0 && nums[i]<0)
            {
                nums[i]=-nums[i];
                k--;
            }
            mini=min(mini,nums[i]);
        }
        sum=accumulate(nums.begin(),nums.end(),0);
        if(k%2!=0)
        {
            sum-=2*mini;
        }
        return sum;
    }
};