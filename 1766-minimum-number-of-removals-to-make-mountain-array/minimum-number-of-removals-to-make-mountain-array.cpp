class Solution {
public:
    void LIS(int n,vector<int>& dp,vector<int>& nums) {
        for(int i=1;i<n;i++) {
            for(int prevInd=0;prevInd<i;prevInd++) {
                if(nums[i] > nums[prevInd] && dp[prevInd] + 1 > dp[i]) {
                    dp[i] = dp[prevInd] + 1;
                }
            }
        }
    }

    void LDS(int n,vector<int>& dp,vector<int>& nums) {
        for(int i=n-2;i>=0;i--) {
            for(int prevInd = n-1;prevInd > i;prevInd--) {
                if(nums[i] > nums[prevInd] && dp[prevInd] + 1 > dp[i]) {
                    dp[i] = dp[prevInd] + 1;
                }
            }
        }
    }

    int minimumMountainRemovals(vector<int>& arr) {
        int n = arr.size();
        vector<int> lis(n,1), lds(n,1);
        LIS(n,lis,arr);
        LDS(n,lds,arr);

        vector<int> suffix(n);
        suffix[n-1] = lds[n-1];
        for(int i=n-2;i>=0;i--) {
            suffix[i] = max(suffix[i+1],lds[i]);
        }

        int maxLength = 0;
        for(int i=1;i<n-1;i++) {
            int currLength = lis[i] + lds[i] - 1;
            if(lis[i] > 1 && lds[i] > 1) {
                maxLength = max(maxLength,currLength);
            }
        }
        return n - maxLength;
    }
};