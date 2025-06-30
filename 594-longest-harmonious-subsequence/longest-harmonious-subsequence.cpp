class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> mp;
        int maxLen=0;
        for(int num:nums) mp[num]++;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            int mini=it->first;
            int maxi=it->first+1;
            if(mp.find(maxi)!=mp.end()) maxLen=max(maxLen,mp[mini]+mp[maxi]);
        }
        return maxLen;
    }
};