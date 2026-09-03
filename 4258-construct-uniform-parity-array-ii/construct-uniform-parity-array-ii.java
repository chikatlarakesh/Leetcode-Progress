class Solution {
    boolean checkParity(int num,int target) {
        if(num % 2 != target % 2) return false;
        return true;
    }

    public boolean uniformArray(int[] nums1) {
        int n = nums1.length;

        int minElement = nums1[0];
        for(int i=0;i<n;i++) {
            minElement = Math.min(minElement,nums1[i]);
        }

        int oddCount = 0, evenCount = 0;
        for(int i=0;i<n;i++) {
            int val = nums1[i];
            if(!checkParity(nums1[i],minElement)) {
                val -= minElement;
            }

            if(val % 2 == 0) evenCount++;
            else oddCount++;
        }
        return evenCount == n || oddCount == n;
    }
}