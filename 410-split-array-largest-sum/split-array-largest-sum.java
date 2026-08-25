class Solution {
    boolean isPossible(int targetSum,int[] nums,int k) {
        int n = nums.length;
        int currSum = 0;
        for(int i=0;i<n;i++) {
            if(nums[i] > targetSum) return false;
            currSum += nums[i];
            if(currSum > targetSum) {
                k--;
                currSum = nums[i];
            }
            
            if(k < 0) return false;
        }
        return true;
    }

    public int splitArray(int[] nums, int k) {
        int n = nums.length;
        if(n == 1) return nums[0];

        int low = 0, high = Integer.MAX_VALUE;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(isPossible(mid,nums,k-1)) {
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return low;
    }
}