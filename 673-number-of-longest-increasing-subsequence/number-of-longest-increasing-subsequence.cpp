class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1), count(n,1);
        int maxLength = 0;
        for(int i=0;i<n;i++) {
            for(int prevInd=0;prevInd<i;prevInd++) {
                if(nums[i] > nums[prevInd] && dp[prevInd] + 1 > dp[i]) {
                    dp[i] = dp[prevInd] + 1;
                    count[i] = count[prevInd];
                }
                else if(nums[i] > nums[prevInd] && dp[prevInd] + 1 == dp[i]) {
                    count[i] += count[prevInd];
                }
            }
            maxLength = max(maxLength, dp[i]);
        }
        
        int totalLISCount = 0;
        for(int i=0;i<n;i++) {
            if(dp[i] == maxLength) {
                totalLISCount += count[i];
            }
        }
        return totalLISCount;
    }
};