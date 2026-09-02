class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length();
        Set<Character> st = new HashSet<>();
        int maxLength = 0;

        int l = 0;
        for(int r=0;r<n;r++) {
            char ch = s.charAt(r);
            while(st.contains(ch)) {
                st.remove(s.charAt(l));
                l++;
            }
            st.add(ch);
            maxLength = Math.max(maxLength,r-l+1);
        }
        return maxLength;
    }
}