vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int a=-1;
        int b=-1;
        int i;
        for(i=0;i<n;i++)
        {
            if(nums[i]==target)
            {
                if(a==-1)
                {
                    a=i;
                }
                b=i;
            }
        }
        if(a==-1)
        {
            return {-1,-1};
        }
        else
        {
            return {a,b};
        }
    }
