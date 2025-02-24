class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int> vec;
        for(int i=0;i<n;i++)
            {
                sort(grid[i].begin(),grid[i].end(),greater<int>());
                int temp=min(limits[i],m);
                for(int j=0;j<temp;j++)
                    {
                        vec.push_back(grid[i][j]);
                    }
            }
        sort(vec.begin(),vec.end(),greater<int>());
        long long sum=0;
        for(int i=0;i<k && i<vec.size();i++)
            {
                sum+=vec[i];
            }
        return sum;
    }
};