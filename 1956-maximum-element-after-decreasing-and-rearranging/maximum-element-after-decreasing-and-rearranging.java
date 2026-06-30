class Solution {
    public int maximumElementAfterDecrementingAndRearranging(int[] arr) {
        int n = arr.length;
        Arrays.sort(arr);
        arr[0] = 1;
        for(int i=1;i<n;i++) {
            if(arr[i] - arr[i-1] <= 1) continue;
            arr[i] = arr[i-1] + 1;
        }
        return arr[n-1];
    }
}