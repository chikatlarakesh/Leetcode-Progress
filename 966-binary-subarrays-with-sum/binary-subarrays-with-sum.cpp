class Solution {
public:
    int atMost(vector<int>& nums, int goal)
    {
        if(goal<0) return 0;
        int n=nums.size();
        int l=0,count=0,sum=0;
        for(int r=0;r<n;r++)
        {
            sum+=nums[r];
            while(sum>goal)
            {
                sum-=nums[l];
                l++;
            }
            count+=r-l+1;
        }
        return count;
    }


    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums,goal)-atMost(nums,goal-1);

        // int totalSubarrays=0,prefixSum=0;
        // unordered_map<int,int> mp;
        // mp[0]=1;
        // for(int i=0;i<n;i++)
        // {
        //     prefixSum+=nums[i];
        //     int complement=prefixSum-goal;
        //     if(mp.find(complement)!=mp.end())
        //     {
        //         totalSubarrays+=mp[complement];
        //     }
        //     mp[prefixSum]++;
        // }
        // return totalSubarrays;
    }
};