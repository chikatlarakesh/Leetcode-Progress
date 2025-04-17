class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int n=nums.size();
        int i,j,count=0;
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(nums[i]==nums[j])
                {
                    if(i*j%k==0)
                    {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};