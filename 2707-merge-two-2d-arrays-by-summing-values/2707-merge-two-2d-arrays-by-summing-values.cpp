class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int i;
        int n=nums1.size();
        int m=nums2.size();
        unordered_map<int,int> mp;
        for(auto &num: nums1)
        {
            mp[num[0]]=num[1];
        }
        for(auto &num: nums2)
        {
            mp[num[0]]+=num[1];
        }
        vector<vector<int>> result;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            result.push_back({it->first,it->second});
        }
        sort(result.begin(),result.end());
        return result;
    }
};