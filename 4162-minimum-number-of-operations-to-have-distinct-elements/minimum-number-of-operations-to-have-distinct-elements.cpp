class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int duplicates = 0;
        
        for(int num : nums) {
            if(mp[num] == 1) duplicates++;
            mp[num]++;
        }

        int i=0,count = 0;
        while(i<n && duplicates > 0) {
            count++;
            for(int j=0;j<3 && i<n;j++) {
                if(mp[nums[i]] == 2) duplicates--;
                mp[nums[i]]--;
                i++;
            }
        }
        return count;
    }
};