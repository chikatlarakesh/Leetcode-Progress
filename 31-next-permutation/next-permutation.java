class Solution {
    void reverse(int[] arr,int i,int j) {
        while(i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    void swap(int[] arr,int i,int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public void nextPermutation(int[] nums) {
        int n = nums.length;
        int ind = -1;
        for(int i=n-2;i>=0;i--) {
            if(nums[i] < nums[i+1]) {
                ind = i;
                break;
            }
        }

        int val = 101;
        int swapIndex = -1;
        if(ind != -1) {
            for(int i=n-1;i>ind;i--) {
                if(nums[i] > nums[ind] && nums[i] < val) {
                    val = nums[i];
                    swapIndex = i;
                } 
            }
        }

        if(swapIndex != -1) swap(nums,ind,swapIndex);
        reverse(nums,ind+1,n-1);
    }
}