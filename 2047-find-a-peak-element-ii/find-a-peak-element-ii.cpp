class Solution {
public:
    int getMaxElement(int n,int col,vector<vector<int>>& mat)
    {
        int maxi=INT_MIN,maxInd=-1;
        for(int i=0;i<n;i++)
        {
            if(mat[i][col]>maxi)
            {
                maxi=mat[i][col];
                maxInd=i;
            }
        }
        return maxInd;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        int low=0,high=m-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int rowInd=getMaxElement(n,mid,mat);
            int left = mid-1>=0 ? mat[rowInd][mid-1] : -1;
            int right = mid+1<m ? mat[rowInd][mid+1] : -1;
            if(mat[rowInd][mid]>left && mat[rowInd][mid]>right) return {rowInd,mid};
            else if(left>mat[rowInd][mid]) high=mid-1;
            else low=mid+1;
        }
        return {-1,-1};


        // vector<int> result(2,-1);
        // int n=mat.size();
        // int m=mat[0].size();

        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<m;j++)
        //     {
        //         int val=mat[i][j];
        //         int left=-1,right=-1,top=-1,bottom=-1;
        //         if(j-1>=0) left=mat[i][j-1];
        //         if(j+1<m) right=mat[i][j+1];
        //         if(i-1>=0) top=mat[i-1][j];
        //         if(i+1<n) bottom=mat[i+1][j];

        //         if(val>left && val>right && val>top && val>bottom)
        //         {
        //             result[0]=i;
        //             result[1]=j;
        //             break;
        //         }
        //     }
        // }
        // return result;
    }
};