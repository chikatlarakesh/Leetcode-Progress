class Solution {
public:
    bool divisor(vector<int>& nums,int threshold,int val)
    {
        int i,temp=0;
        int n=nums.size();
        for(i=0;i<n;i++)
        {
            temp=nums[i]/val;
            if(nums[i]%val!=0)
            {
                temp++;
            }
            threshold=threshold-temp;
        }
        if(threshold<0)
        {
            return false;
        }
        return true;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        bool result;
        int l=1;
        int r=1000000;
        while(l<=r)
        {
            int m=l+(r-l)/2;
            result=divisor(nums,threshold,m);
            if(result==true)
            {
                r=m-1;
            }
            else
            {
                l=m+1;
            }
        }
        return l;
    }
};