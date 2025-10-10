class Solution {
public:
    int maxEnergy(int i,int n,int k,vector<int>& energy,vector<int>& dp) {
        if(i>=n) return 0;
        if(dp[i] != -1) return dp[i];
        return dp[i] = energy[i] + maxEnergy(i+k,n,k,energy,dp);
    }

    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        int maxi = INT_MIN;
        vector<int> dp(n,-1);
        for(int i=0;i<n;i++) {
            maxi = max(maxi,maxEnergy(i,n,k,energy,dp));
        }
        return maxi;
    }
};