class Solution {
    public String reverseWords(String s) {
        s = s.trim();
        int n = s.length();
        Stack<Character> st = new Stack<>();
        StringBuilder sb = new StringBuilder();

        int i = n-1;
        while(i >= 0) {
            char ch = s.charAt(i);
            if(ch == ' ') {
                while(s.charAt(i) == ' ') i--;
                while(!st.isEmpty()) {
                    sb.append(st.pop());
                }
                sb.append(' ');
            }
            else {
                st.push(ch);
                i--;
            }
        }

        while(!st.isEmpty()) {
            sb.append(st.pop());
        }
        return sb.toString();
    }
}