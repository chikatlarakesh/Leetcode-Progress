class Solution {
    public List<List<Integer>> findDisappearedNumbers(int[] nums, int lower, int upper) {
        Arrays.sort(nums);
        int n = nums.length;
        List<List<Integer>> result = new ArrayList<>();

        int start = lower;
        for(int i=0;i<n;i++) {
            if(nums[i] < start) continue;
            if(nums[i] > upper) break;
            if(nums[i] > start) {
                int end = nums[i] - 1;
                result.add(Arrays.asList(start,end));
            }
            start = nums[i] + 1;
        }

        if(start <= upper) result.add(Arrays.asList(start,upper));
        return result;
    }
}