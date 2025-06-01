class Solution {
public:
    int findMinimum(vector<int>& nums)
    {
        int n=nums.size();
        int mini=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0 && nums[i]<mini)
            {
                mini=nums[i];
            }
        }
        return mini;
    }

    int minimumOperations(vector<int>& nums) {
        int n=nums.size();
        int minOperations=0;
        for(int i=0;i<n;i++)
        {
            int minElement=findMinimum(nums);
            if(minElement==INT_MAX) break;
            else
            {
                for(int j=0;j<n;j++)
                {
                    nums[j]-=minElement;
                }
                minOperations++;
            }
        }
        return minOperations;
    }
};