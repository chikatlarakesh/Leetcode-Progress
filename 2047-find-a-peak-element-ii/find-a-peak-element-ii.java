class Solution {
    int findMaximum(int ind,int n,int[][] mat) {
        int maxElement = -1, maxIndex = -1;
        for(int i = 0;i<n;i++) {
            if(mat[i][ind] > maxElement) {
                maxElement = mat[i][ind];
                maxIndex = i;
            }
        }
        return maxIndex;
    }

    public int[] findPeakGrid(int[][] mat) {
        int n = mat.length;
        int m = mat[0].length;

        int low = 0, high = m - 1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            int maxIndex = findMaximum(mid,n,mat);
            int left = mid - 1 >= 0 ? mat[maxIndex][mid-1] : -1;
            int right = mid + 1 < m ? mat[maxIndex][mid+1] : -1;
            if(mat[maxIndex][mid] > left && mat[maxIndex][mid] > right) {
                return new int[]{maxIndex,mid};
            }
            else if(mat[maxIndex][mid] < left) high = mid - 1;
            else low = mid + 1;
        }
        return new int[]{-1,-1};
    }
}