class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        long long prefixSum=0;
        int totalSubarrays=0;
        unordered_map<long long,int> mp;
        mp[0]=1;
        for(int i=0;i<n;i++)
        {
            prefixSum+=nums[i];
            int complement=prefixSum-k;
            if(mp.find(complement)!=mp.end()) totalSubarrays+=mp[complement];
            mp[prefixSum]++;
        }
        return totalSubarrays;
    }
};