int majorityElement(vector<int>& nums) {
        int count=0;
        int result = 0;
        int n=nums.size();
        for(int i =0;i<n;i++)
        {
            if(count==0)
            {
                result=nums[i];
            }
            if(result==nums[i])
            {
                count++;
            }
            else
            {
                count--;
            }
        }
        return result;
    }
