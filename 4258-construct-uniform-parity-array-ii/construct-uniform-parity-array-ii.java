class Solution {
    public boolean uniformArray(int[] nums1) {
        int n = nums1.length;

        int minElement = nums1[0];
        int oddCount = 0, evenCount = 0;
        for(int i=0;i<n;i++) {
            minElement = Math.min(minElement,nums1[i]);
            if(nums1[i] % 2 == 0) evenCount++;
            else oddCount++;
        }
        
        if(minElement % 2 == 0 && oddCount > 0) return false;
        return true;
    }
}