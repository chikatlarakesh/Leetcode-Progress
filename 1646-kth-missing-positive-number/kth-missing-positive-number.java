class Solution {
    public int findKthPositive(int[] arr, int k) {
        int n = arr.length;
        int[] missing = new int[n];

        for(int i=0;i<n;i++) {
            missing[i] = arr[i] - (i + 1);
        }

        int low = 0, high = n - 1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(missing[mid] < k) {
                low = mid + 1;
            }
            else high = mid - 1;
        }
        
        int result = k;
        if(high >= 0) {
            int remaining = k - missing[high];
            result = arr[high] + remaining;
        }
        return result;
    }
}