class Solution {
    public String removeOuterParentheses(String s) {
        int n = s.length();
        Queue<Character> q = new LinkedList<>();
        StringBuilder sb = new StringBuilder();

        int count = 0;
        for(int i=0;i<n;i++) {
            char ch = s.charAt(i);
            if(ch == '(') count++;
            else count--;
            q.offer(ch);
            
            if(count == 0) {
                q.poll();
                while(q.size() > 1) {
                    sb.append(q.poll());
                }
                q.poll();
            }
        }
        return sb.toString();
    }
}