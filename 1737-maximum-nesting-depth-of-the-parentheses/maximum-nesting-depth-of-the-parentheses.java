class Solution {
    public int maxDepth(String s) {
        int n = s.length();
        int count = 0, maxDepth = 0;

        for(int i=0;i<n;i++) {
            char ch = s.charAt(i);
            if(ch == '(') count++;
            else if(ch == ')') count--;
            maxDepth = Math.max(maxDepth,count);
        }
        return maxDepth;
    }
}