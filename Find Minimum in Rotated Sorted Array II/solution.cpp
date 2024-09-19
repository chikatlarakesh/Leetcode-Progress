int findMin(vector<int>& nums) {
        int minimum=5001;
        int n=nums.size();
        int low=0;
        int high=n-1;
        int mid;
        while(low<=high)
        {
            mid=low+(high-low)/2;
            if(nums[low]==nums[mid] && nums[mid]==nums[high])
            {
                minimum=min(minimum,nums[low]);
                low++;
                high--;
                continue;
            }
            if(nums[mid]<=nums[high])
            {
                minimum=min(minimum,nums[mid]);
                high=mid-1;
            }
            else
            {
                minimum=min(minimum,nums[low]);
                low=mid+1;
            }
        }
        return minimum;
    }
