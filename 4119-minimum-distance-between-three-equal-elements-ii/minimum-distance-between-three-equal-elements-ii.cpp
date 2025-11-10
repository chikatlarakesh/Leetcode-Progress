class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,vector<int>> mp;

        for(int i=0;i<n;i++) {
            mp[nums[i]].push_back(i);
        }

        int minDist = INT_MAX;
        for(auto &it: mp) {
            int val = it.first;
            vector<int> temp = it.second;
            if(temp.size() >= 3) {
                int m = temp.size();
                for(int i=2;i<m;i++) {
                    minDist = min(minDist, 2 * (temp[i] - temp[i-2]));
                }
            }
        }
        if(minDist == INT_MAX) minDist = -1;
        return minDist;
    }
};