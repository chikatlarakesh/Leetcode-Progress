class Solution {
    public int longestConsecutive(int[] nums) {
        HashSet<Integer> st = new HashSet<>();
        for(int num : nums) {
            st.add(num);
        }

        int maxLength = 0;
        for(int num : st) {
            if(st.contains(num-1)) continue;
            int count = 1;
            int val = num + 1;
            while(st.contains(val)) {
                count++;
                val++;
            }
            maxLength = Math.max(maxLength,count);
        }
        return maxLength;
    }
}