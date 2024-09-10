void sortColors(vector<int>& nums) {
        int i,temp,j;
        int n=nums.size();
        for(i=0;i<n-1;i++)
        {
            int count=0;
            for(j=0;j<n-i-1;j++)
            {
                if(nums[j]>nums[j+1])
                {
                    temp=nums[j];
                    nums[j]=nums[j+1];
                    nums[j+1]=temp;
                    count++;
                }
            }
            if(count==0)
            {
                break;
            }
        }
    }
