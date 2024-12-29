class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int n=matrix.size();
        int m=matrix[0].size();
        int i,left=0,right=m-1,bottom=n-1,top=0;
        while(top<=bottom && left<=right)
        {
            for(i=left;i<=right;i++)
            {
                result.push_back(matrix[top][i]);
            }
            top++;
            for(i=top;i<=bottom;i++)
            {
                result.push_back(matrix[i][right]);
            }
            right--;
            if(top<=bottom)
            {
                for(i=right;i>=left;i--)
                {
                    result.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            if(left<=right)
            {
                for(i=bottom;i>=top;i--)
                {
                    result.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return result;
    }
};