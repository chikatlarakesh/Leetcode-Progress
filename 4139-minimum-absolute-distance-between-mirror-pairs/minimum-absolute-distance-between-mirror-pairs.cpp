class Solution {
public:
    int reverseDigits(int num) {
        string s = to_string(num);
        reverse(s.begin(),s.end());
        int val = stoi(s);
        return val;
    }
    
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        mp[reverseDigits(nums[0])] = 0;
        int minDist = INT_MAX;

        for(int j=1;j<n;j++) {
            if(mp.find(nums[j]) != mp.end()) {
                int i = mp[nums[j]];
                minDist = min(minDist, j - i);
            }
            int newVal = reverseDigits(nums[j]);
            mp[newVal] = j;
        }
        if(minDist == INT_MAX) minDist = -1;
        return minDist;
    }
};