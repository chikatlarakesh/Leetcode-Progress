class Solution {
public:
    bool isPossible(int maxSum,vector<int>& nums,int partitions)
    {
        int n=nums.size();
        int currSum=0;
        for(int i=0;i<n;i++)
        {
            if(currSum+nums[i]<=maxSum)
            {
                currSum+=nums[i];
            }
            else
            {
                partitions--;
                currSum=nums[i];
            }
            if(partitions<0) return false;
        }
        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(isPossible(mid,nums,k-1)) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};