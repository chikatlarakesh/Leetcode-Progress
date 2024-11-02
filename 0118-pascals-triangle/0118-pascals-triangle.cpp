class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        int i,j;
        for(i=0;i<numRows;i++)
        {
            vector<int> v(i+1,1);
            for(j=1;j<i;j++)
            {
                v[j]=result[i-1][j-1]+result[i-1][j];
            }
            result.push_back(v);
        }
        return result;
    }
};