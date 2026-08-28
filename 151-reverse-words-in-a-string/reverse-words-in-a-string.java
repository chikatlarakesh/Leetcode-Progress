class Solution {
    public String reverseWords(String s) {

        StringBuilder sb = new StringBuilder(s);
        int n = sb.length();

        // Reverse the entire string
        sb.reverse();

        int i = 0, j = 0;

        while (j < n) {

            // Skip spaces
            while (j < n && sb.charAt(j) == ' ') {
                j++;
            }

            int start = i;

            // Copy the word to the front
            while (j < n && sb.charAt(j) != ' ') {
                sb.setCharAt(i, sb.charAt(j));
                i++;
                j++;
            }

            int end = i;

            // Reverse the current word
            reverse(sb, start, end - 1);

            // Add one space after the word
            if (j < n) {
                sb.setCharAt(i, ' ');
                i++;
            }
        }

        // Remove trailing space
        if (i > 0 && sb.charAt(i - 1) == ' ') {
            i--;
        }

        return sb.substring(0, i);
    }

    private void reverse(StringBuilder sb, int left, int right) {
        while (left < right) {
            char temp = sb.charAt(left);
            sb.setCharAt(left, sb.charAt(right));
            sb.setCharAt(right, temp);

            left++;
            right--;
        }
    }
}