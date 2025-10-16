class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int,int> mp;
        for(int num:nums) {
            int val = ((num % value) + value) % value;
            mp[val]++;
        }

        int i = 0;
        while(true) {
            int r = i % value;
            if(mp[r] > 0) mp[r]--;
            else break;
            i++;
        }
        return i;
    }
};