class Solution {
    int countSubarrays(int[] nums,int target) {
        int n = nums.length;

        int oddCount = 0, l = 0,count = 0;
        for(int r = 0; r < n; r++) {
            if(nums[r] % 2 == 1) oddCount++;
            
            while(l < n && oddCount > target) {
                if(nums[l] % 2 == 1) oddCount--;
                l++;
            }

            count += r - l + 1;
        }
        return count;
    }

    public int numberOfSubarrays(int[] nums, int k) {
        int n = nums.length;

        int result = countSubarrays(nums,k) - countSubarrays(nums,k-1);
        return result;
    }
}