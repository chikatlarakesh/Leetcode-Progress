class Solution {
public:
    bool ispossible(vector<int>& nums, int op, int k)
    {
        int n=nums.size();
        int i,temp;
        for(i=0;i<n;i++)
        {
            temp=0;
            if(nums[i]>k)
            {
                temp=nums[i]/k;
                if(nums[i]%k!=0)
                {
                    temp++;
                }
                temp--;
            }
            op=op-temp;
            if(op<0)
            {
                return false;
            }
        }
        return true;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int n=nums.size();
        int l=1;
        int r=1000000000;
        while(l<=r)
        {
            int m=l+(r-l)/2;
            if(ispossible(nums,maxOperations,m)==false)
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
};