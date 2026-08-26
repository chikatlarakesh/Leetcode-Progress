class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int n = matrix.length;
        int m = matrix[0].length;
        int low = 0, high = n-1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            int val = matrix[mid][0];
            if(val == target) return true;
            else if(val < target) {
                low = mid + 1;
            }
            else high = mid - 1;
        }

        int row = high;
        if(row < 0) return false;
        low = 0; high = m-1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            int val = matrix[row][mid];
            if(val == target) return true;
            else if(val < target) {
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return false;
    }
}