class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int val = k;
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int num:nums) mp[num]++;

        while(true) {
            if(mp.find(val) == mp.end()) return val;
            val += k;
        }
        return -1;
    }
};