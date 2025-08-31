class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();

        // int i=0,j=m-1;
        // while(i<n && j>=0)
        // {
        //     if(matrix[i][j]==target) return true;
        //     else if(matrix[i][j]<target) i++;
        //     else j--;
        // }
        // return false;

        int low=0,high=n-1,col=0;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(matrix[mid][col]==target) return true;
            else if(matrix[mid][col]>target) high=mid-1;
            else low=mid+1;
        }
        if(high<0) return false;

        int row=high;
        low=0, high=m-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(matrix[row][mid]==target) return true;
            else if(matrix[row][mid]>target) high=mid-1;
            else low=mid+1;
        }
        return false;
    }
};