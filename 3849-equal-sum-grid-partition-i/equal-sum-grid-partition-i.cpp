class Solution {
public:
    void sumOfRows(int m,int n,vector<long long>& rows,vector<vector<int>>& grid)
    {
        int i,j;
        long long prevRowSum=0;
        for(i=0;i<n;i++)
        {
            long long sum=0;
            for(j=0;j<m;j++)
            {
                sum+=grid[i][j];
            }
            rows[i]=prevRowSum+sum;
            prevRowSum=rows[i];
        }
    }

    void sumOfColumns(int m,int n,vector<long long> &columns,vector<vector<int>>& grid)
    {
        int i,j;
        long long prevColSum=0;
        for(i=0;i<m;i++)
        {
            long long sum=0;
            for(j=0;j<n;j++)
            {
                sum+=grid[j][i];
            }
            columns[i]=prevColSum+sum;
            prevColSum=columns[i];
        }
    }

    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<long long> rows(n);
        vector<long long> columns(m);
        sumOfRows(m,n,rows,grid);
        sumOfColumns(m,n,columns,grid);
        for(int i=0;i<n-1;i++)
        {
            long long leftSum=rows[i];
            long long rightSum=rows[n-1]-rows[i];
            if(leftSum==rightSum) return true;
        }
        for(int i=0;i<m-1;i++)
        {
            long long leftSum=columns[i];
            long long rightSum=columns[m-1]-columns[i];
            if(leftSum==rightSum) return true;
        }
        return false;
    }
};