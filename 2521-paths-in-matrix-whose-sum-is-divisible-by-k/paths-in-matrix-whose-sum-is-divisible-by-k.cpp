class Solution {
public:
    const int MOD = 1e9 + 7;
    int totalPaths(int i,int j,int k,int rem,vector<vector<int>>& grid,vector<vector<vector<int>>>& dp) {
        if(i < 0 || j < 0) return 0;
        if(dp[i][j][rem] != -1) return dp[i][j][rem];
        if(i == 0 && j == 0) {
            int newRem = (rem + grid[i][j]) % k;
            if(newRem % k == 0) return 1;
            else return 0;
        }

        int newRem = (rem + grid[i][j]) % k;
        int left = totalPaths(i,j-1,k,newRem,grid,dp);
        int up = totalPaths(i-1,j,k,newRem,grid,dp);
        return dp[i][j][rem] = (left + up) % MOD;
    }

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(k,-1)));
        return totalPaths(n-1,m-1,k,0,grid,dp);
    }
};