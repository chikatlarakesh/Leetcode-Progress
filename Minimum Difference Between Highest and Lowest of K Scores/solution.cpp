int minimumDifference(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int l=0;
        int r;
        int result=INT_MAX;
        int minimum=INT_MAX;
        for(r=0;r<n;r++)
        {
            if(r-l+1==k)
            {
                minimum=nums[r]-nums[l];
                result=min(minimum,result);
                l++;
            }
        }
        return result;
    }
