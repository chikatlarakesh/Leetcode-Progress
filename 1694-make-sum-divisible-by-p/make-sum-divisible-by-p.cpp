class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n=nums.size();
        int rem=0;
        for(int num:nums) rem=(rem+num)%p;
        if(rem==0) return 0;
        unordered_map<int,int> mp;
        mp[0]=-1;
        int minLen=n,prefixRem=0;
        for(int i=0;i<n;i++)
        {
            prefixRem=(prefixRem+nums[i])%p;
            int target=(prefixRem-rem+p)%p;
            if(mp.find(target)!=mp.end())
            {
                minLen=min(minLen,i-mp[target]);
            }
            mp[prefixRem]=i;
        }
        if(minLen==n) return -1;
        return minLen;
    }
};