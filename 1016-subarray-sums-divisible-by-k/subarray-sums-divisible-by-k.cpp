class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mp;
        mp[0]=1;
        int totalSubarrays=0,prefixSum=0;
        for(int i=0;i<n;i++)
        {
            prefixSum=(prefixSum+ nums[i] % k + k) % k;
            totalSubarrays+=mp[prefixSum];
            mp[prefixSum]++;
        }
        return totalSubarrays;
    }
};