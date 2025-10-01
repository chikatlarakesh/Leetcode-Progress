class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums;
        sort(nums.begin(),nums.end());
        vector<int> dp(n,1), hash(n);
        int maxLength = 0, ind = -1;
        dp[0] = 1;
        for(int i=1;i<n;i++) {
            hash[i] = i;
            for(int prevInd = 0;prevInd < i;prevInd++) {
                if(nums[i] % nums[prevInd] == 0 && dp[prevInd] + 1 > dp[i]) {
                    dp[i] = dp[prevInd] + 1;
                    hash[i] = prevInd;
                }
            }
            if(dp[i] > maxLength) {
                maxLength = dp[i];
                ind = i;
            }
        }

        vector<int> result;
        while(hash[ind] != ind) {
            result.push_back(nums[ind]);
            ind = hash[ind];
        }
        result.push_back(nums[ind]);
        reverse(result.begin(),result.end());
        return result;
    }
};