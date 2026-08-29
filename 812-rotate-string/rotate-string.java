class Solution {
    public boolean rotateString(String s, String goal) {
        StringBuilder sb = new StringBuilder(s);
        // same string twice
        sb.append(s);

        int n = s.length();
        int len = n + n;
        int i = 0, j = n - 1;
        while(i < len && j < len) {
            StringBuilder str = new StringBuilder(sb.substring(i,j+1));
            if(goal.equals(str.toString())) return true;
            i++;
            j++;
        }
        return false;
    }
}