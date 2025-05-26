class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        int n=nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]=i;
        }
        int m=operations.size();
        for(int i=0;i<m;i++)
        {
            int ind=mp[operations[i][0]];
            int newVal=operations[i][1];
            nums[ind]=newVal;
            mp.erase(operations[i][0]);
            mp[newVal]=ind;
        }
        return nums;
    }
};