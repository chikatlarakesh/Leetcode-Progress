class Solution {
public:
    int negative(vector<int>& nums)
    {
        int n=nums.size();
        int sum=0;
        int l=0;
        int r=n-1;
        while(l<=r)
        {
            int m=l+(r-l)/2;
            if(nums[m]>=0)
            {
                r=m-1;
            }
            else
            {
                l=m+1;
            }
        }
        return r;
    }
    int positive(vector<int>& nums)
    {
        int n=nums.size();
        int sum=0;
        int l=0;
        int r=n-1;
        while(l<=r)
        {
            int m=l+(r-l)/2;
            if(nums[m]<=0)
            {
                l=m+1;
            }
            else
            {
                r=m-1;
            }
        }
        return l;
    }
    int maximumCount(vector<int>& nums) {
        int n=nums.size();
        int neg=negative(nums)+1;
        int pos=n-positive(nums);
        int sum=max(neg,pos);
        return sum;
    }
};