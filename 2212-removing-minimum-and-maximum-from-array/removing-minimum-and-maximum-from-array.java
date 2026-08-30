class Solution {
    public int minimumDeletions(int[] nums) {
        int n = nums.length;
        int minIndex = 0, maxIndex = 0;
        int maxElement = nums[0], minElement = nums[0];

        for(int i=1;i<n;i++) {
            if(nums[i] > maxElement) {
                maxElement = nums[i];
                maxIndex = i;
            }
            if(nums[i] < minElement) {
                minElement = nums[i];
                minIndex = i;
            }
        }

        int minDeletions = n;

        if(minIndex < maxIndex) {
            int left = minIndex + 1;
            int right = n - maxIndex;
            minDeletions = Math.min(minDeletions,left+right);

            int bothLeft = maxIndex + 1;
            int bothRight = n - minIndex;
            minDeletions = Math.min(minDeletions,bothLeft);
            minDeletions = Math.min(minDeletions,bothRight);
        }
        else if(maxIndex < minIndex) {
            int left = maxIndex + 1;
            int right = n - minIndex;
            minDeletions = Math.min(minDeletions,left+right);

            int bothLeft = minIndex + 1;
            int bothRight = n - maxIndex;
            minDeletions = Math.min(minDeletions,bothLeft);
            minDeletions = Math.min(minDeletions,bothRight);
        }
        else {
            int left = maxIndex + 1;
            int right = n - minIndex;
            minDeletions = Math.min(minDeletions,Math.min(left,right));
        }

        return minDeletions;
    }
}