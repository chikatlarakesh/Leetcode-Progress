class Solution {
    public int removeDuplicates(int[] nums) {
        int n = nums.length;
        if(n == 1) return 1;
        int i = 1, j = 1;
        while(j < n) {
            if(nums[j] != nums[i-1]) {
                nums[i] = nums[j];
                i++;
            }
            j++;
        }
        return i;
    }
}