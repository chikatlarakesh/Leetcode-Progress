class Solution {
public:
    bool isPossible(vector<int>& nums, int k, int m)
    {
        int i=0;
        int n=nums.size();
        while(i<n)
        {
            if(nums[i]<=m)
            {
                k--;
                i+=2;
            }
            else
            {
                i++;
            }
            if(k<=0)
            {
                return true;
            }
        }
        return false;
    }

    int minCapability(vector<int>& nums, int k) {
        int l= *min_element(nums.begin(),nums.end());
        int r= *max_element(nums.begin(),nums.end());
        while(l<=r)
        {
            int m=l+(r-l)/2;
            if(isPossible(nums,k,m))
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