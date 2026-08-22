class Solution {
    void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public void sortColors(int[] nums) {
        int n = nums.length;
        int i = 0,j = 0,k = n-1;
        while(j <= k) {
            if(nums[j] == 1) j++;
            else if(nums[j] == 0) {
                swap(nums,i,j);
                i++;
                j++;
            }
            else {
                swap(nums,j,k);
                k--;
            }
        }
    }
}