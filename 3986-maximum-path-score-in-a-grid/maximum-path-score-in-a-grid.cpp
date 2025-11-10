class Solution {
public:
    int getCost(int i,int j,vector<vector<int>>& grid) {
        if(grid[i][j] == 0) return 0;
        return 1;
    }
    
    int maxScore(int i,int j,int n,int m,vector<vector<int>>& grid, int k,vector<vector<vector<int>>>& dp) {
        if(i >= n || j >= m) return -1000000000;
        int cost = getCost(i,j,grid);
        if(k < cost) return -1000000000;

        if(i == n-1 && j == m-1) return grid[i][j];
        if(dp[i][j][k] != INT_MIN) return dp[i][j][k];

        int score = grid[i][j];
        
        int right = maxScore(i,j+1,n,m,grid,k-cost,dp);
        int down = maxScore(i+1,j,n,m,grid,k-cost,dp);

        return dp[i][j][k] = score + max(right,down);
    }
    
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(k+1,INT_MIN)));
        int result = maxScore(0,0,n,m,grid,k,dp);
        if(result < 0) return -1;
        return result;
    }
};