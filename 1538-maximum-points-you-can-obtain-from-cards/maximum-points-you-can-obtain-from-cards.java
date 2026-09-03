class Solution {
    public int maxScore(int[] nums, int k) {
        int n = nums.length;

        int leftSum = 0,rightSum = 0;
        for(int i=0;i<k;i++) {
            leftSum += nums[i];
        }

        int maxSum = leftSum, rightIndex = n-1;
        for(int i=k-1;i>=0;i--) {
            leftSum -= nums[i];
            rightSum += nums[rightIndex];
            rightIndex--;

            maxSum = Math.max(maxSum,leftSum + rightSum);
        }
        return maxSum;
    }
}