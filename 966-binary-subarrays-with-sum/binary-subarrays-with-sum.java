class Solution {
    int countSubarrays(int[] nums,int target) {
        int n = nums.length;
        if(target == -1) return 0;

        int count = 0, l = 0,sum = 0;
        for(int r = 0; r < n; r++) {
            sum += nums[r];
            
            while(l < n && sum > target) {
                sum -= nums[l];
                l++;
            }

            count += r - l + 1;
        }
        return count;
    }

    public int numSubarraysWithSum(int[] nums, int goal) {
        int n = nums.length;

        int result = countSubarrays(nums,goal) - countSubarrays(nums,goal-1);
        return result;
    }
}