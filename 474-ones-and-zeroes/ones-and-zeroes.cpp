class Solution {
public:
    pair<int,int> getBinaryCount(string &s) {
        int zeroes = 0, ones = 0;
        for(char ch: s) {
            if(ch == '0') zeroes++;
            else ones++;
        }
        return {zeroes,ones};
    }

    int findLargestSubset(int i, int m, int n,vector<pair<int,int>>& arr,vector<vector<vector<int>>>& dp) {
        if(i < 0) return 0;
        if(dp[i][m][n] != -1) return dp[i][m][n];

        int zeroCount = arr[i].first;
        int oneCount = arr[i].second;

        int take = 0, notTake = 0;
        if(m >= zeroCount && n >= oneCount) take = 1 + findLargestSubset(i-1,m-zeroCount,n-oneCount,arr,dp);
        notTake = findLargestSubset(i-1,m,n,arr,dp);
        return dp[i][m][n] = max(take, notTake);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        int size = strs.size();
        vector<pair<int,int>> binaryCount;
        for(string& s: strs) {
            binaryCount.push_back(getBinaryCount(s));
        }

        vector<vector<vector<int>>> dp(size,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return findLargestSubset(size-1,m,n,binaryCount,dp);
    }
};