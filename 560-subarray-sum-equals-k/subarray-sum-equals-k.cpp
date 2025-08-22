class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mp;
        int prefixSum=0,count=0;
        mp[0]=1;
        for(int i=0;i<n;i++)
        {
            prefixSum+=nums[i];
            if(mp.find(prefixSum-k)!=mp.end()) count+=mp[prefixSum-k];
            mp[prefixSum]++;
        }
        return count;
    }
};