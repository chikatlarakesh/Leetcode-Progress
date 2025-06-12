class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long count=0,total=1;
        int n=nums.size();
        unordered_map<int,int> mp;
        mp[nums[n-1]-(n-1)]++;
        for(int i=n-2;i>=0;i--)
        {
            count+=total;
            count-=mp[nums[i]-i];
            mp[nums[i]-i]++;
            total++;
        }
        return count;
    }
};