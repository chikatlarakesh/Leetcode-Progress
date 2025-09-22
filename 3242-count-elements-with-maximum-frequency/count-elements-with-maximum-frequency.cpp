class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> mp;
        int maxFreq=0;
        for(int num:nums)
        {
            mp[num]++;
            maxFreq=max(maxFreq,mp[num]);
        }
        int count=0;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            if(it->second==maxFreq) count++;
        }
        return maxFreq*count;
    }
};