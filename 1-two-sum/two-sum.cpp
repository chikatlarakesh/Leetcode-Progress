class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        int n=nums.size();
        int i,j=0;
        for(i=0;i<n;i++)
        {
            int complement=target-nums[i];
            if(mp.find(complement)!=mp.end())
            {
                j=mp[complement];
                break;
            }
            mp[nums[i]]=i;
        }
        return {i,j};
    }
};