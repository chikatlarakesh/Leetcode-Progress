int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        int mid;
        while(high>=low)
        {
            mid=(low+high)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            if(nums[mid]<target)
            {
                low=mid+1;
            }
            if(nums[mid]>target)
            {
                high=mid-1;
            }
        }
        return low;
    }
