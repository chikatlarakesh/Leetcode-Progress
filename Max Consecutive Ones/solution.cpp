int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int i;
        int count=0;
        int k=0;
        for(i=0;i<n;i++)
        {
            if(nums[i]==1)
            {
                count++;
            }
            else
            {
                k=max(count,k);
                count=0;
            }
        }
        k=max(count,k);
        return k;
    }
