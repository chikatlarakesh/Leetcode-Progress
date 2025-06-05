class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        int totalSubarrays=0,prefixSum=0;
        unordered_map<int,int> mp;
        mp[0]=1;
        for(int i=0;i<n;i++)
        {
            prefixSum+=nums[i];
            int complement=prefixSum-goal;
            if(mp.find(complement)!=mp.end())
            {
                totalSubarrays+=mp[complement];
            }
            mp[prefixSum]++;
        }
        return totalSubarrays;
    }
};