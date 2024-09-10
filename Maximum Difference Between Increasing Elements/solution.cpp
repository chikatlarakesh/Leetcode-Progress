int maximumDifference(vector<int>& nums) {
        int temp,i,j;
        int n=nums.size();
        int difference =0;
        int low=nums[0];
        for(i=0;i<n-1;i++)
        {
            temp=nums[i+1]-low;
            if(temp>difference)
            {
                difference=temp;
            }
            if(nums[i+1]<low)
            {
                low=nums[i+1];
            }
        }
        if(difference==0)
        {
            return -1;
        }
        else
        {
            return difference;
        }
    }
