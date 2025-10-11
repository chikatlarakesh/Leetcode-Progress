class Solution {
public:
    using ll = long long;
    long long maxDamage(int i,int n,unordered_map<ll,ll>& freq,vector<int>& power,vector<ll>& dp) {
        if(i<0) return 0;
        if(dp[i] != -1) return dp[i];

        int j = i-1;
        while(j>=0 && power[j] >= power[i] - 2) j--;
        ll take = 0,notTake = 0;
        take = (power[i] * freq[power[i]]) + maxDamage(j,n,freq,power,dp);
        notTake = maxDamage(i-freq[power[i]],n,freq,power,dp);
        return dp[i] = max(take,notTake);
    }

    long long maximumTotalDamage(vector<int>& power) {
        int n = power.size();
        sort(power.begin(),power.end());
        unordered_map<ll,ll> freq;
        for(int num: power) freq[num]++;

        vector<ll> dp(n,-1);
        return maxDamage(n-1,n,freq,power,dp);
    }
};