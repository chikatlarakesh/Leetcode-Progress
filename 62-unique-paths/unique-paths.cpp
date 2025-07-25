class Solution {
public:
    int possiblePaths(int i,int j,vector<vector<int>>& dp)
    {
        if(i<0 || j<0) return 0;
        if(i==0 && j==0) return 1;
        if(dp[i][j]!=-1) return dp[i][j];

        int top=possiblePaths(i-1,j,dp);
        int left=possiblePaths(i,j-1,dp);
        return dp[i][j]=top+left;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return possiblePaths(m-1,n-1,dp);
    }
};