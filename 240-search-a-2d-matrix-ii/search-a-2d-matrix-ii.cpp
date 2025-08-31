class Solution {
public:
    bool bs(int low,int high,vector<int>& nums,int target)
    {
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]==target) return true;
            else if(nums[mid]>target) high=mid-1;
            else low=mid+1;
        }
        return false;
    }

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

        for(int i=0;i<n;i++)
        {
            if(bs(0,m-1,matrix[i],target)) return true;
        }
        return false;
    }
};