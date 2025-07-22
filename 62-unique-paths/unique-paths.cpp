class Solution {
public:
    int dfs(int row,int col,int rowSize,int colSize,vector<vector<int>>& matrix,vector<vector<int>>& dp)
    {
        if(row>=rowSize || col>=colSize || matrix[row][col]==-1) return 0;
        if(row==rowSize-1 && col==colSize-1) return 1;
        if(dp[row][col]!=-1) return dp[row][col];
        matrix[row][col]=-1;
        int uniquePaths=dfs(row,col+1,rowSize,colSize,matrix,dp)+dfs(row+1,col,rowSize,colSize,matrix,dp);
        matrix[row][col]=0;
        return dp[row][col]=uniquePaths;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> matrix(m,vector<int>(n,0));
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return dfs(0,0,m,n,matrix,dp);
    }
};