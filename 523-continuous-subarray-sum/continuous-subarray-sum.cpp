class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mp;
        mp[0]=0;
        int prefixSum=0;
        for(int i=0;i<n;i++)
        {
            prefixSum+=nums[i];
            int rem=prefixSum%k;
            if(mp.find(rem)!=mp.end())
            {
                int ind=mp[rem];
                if(i-ind+1>=2) return true;
            }
            else mp[rem]=i+1;
        }
        return false;
    }
};