class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        vector<int> result(2,0);
        int n=mat.size();
        int m=mat[0].size();
        int maxOnes=0;
        for(int i=0;i<n;i++)
        {
            int ones=0;
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==1) ones++;
            }
            if(ones>maxOnes)
            {
                result[0]=i;
                result[1]=ones;
                maxOnes=ones;
            }
        }
        return result;
    }
};