vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int i;
        int count=0;
        int sum=1;
        for(i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                count++;
            }
            else
            {
                sum=sum*nums[i];
            }
        }
        for(i=0;i<n;i++)
        {
            if(count==0)
            {
                nums[i]=sum/nums[i];
            }
            else if(count==1)
            {
                if(nums[i]==0)
                {
                    nums[i]=sum;
                }
                else
                {
                    nums[i]=0;
                }
            }
            else
            {
                nums[i]=0;
            }
        }
        return nums;
    }
