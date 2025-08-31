class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        vector<int> result(2,-1);
        int n=mat.size();
        int m=mat[0].size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int val=mat[i][j];
                int left=-1,right=-1,top=-1,bottom=-1;
                if(j-1>=0) left=mat[i][j-1];
                if(j+1<m) right=mat[i][j+1];
                if(i-1>=0) top=mat[i-1][j];
                if(i+1<n) bottom=mat[i+1][j];

                if(val>left && val>right && val>top && val>bottom)
                {
                    result[0]=i;
                    result[1]=j;
                    break;
                }
            }
        }
        return result;
    }
};