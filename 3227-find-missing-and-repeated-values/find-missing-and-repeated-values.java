class Solution {
    public int[] findMissingAndRepeatedValues(int[][] nums) {
        int n = nums.length;
        int size = n * n;
        HashSet<Integer> st = new HashSet<>();
        int repeating = -1, missing = -1,currSum = 0;
        int actualSum = (size * (size+1)) / 2;

        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                int num = nums[i][j];
                currSum += num;
                if(st.contains(num)) repeating = num;
                st.add(num);
            }
        }

        missing = actualSum - (currSum - repeating);
        return new int[]{repeating,missing};
    }
}