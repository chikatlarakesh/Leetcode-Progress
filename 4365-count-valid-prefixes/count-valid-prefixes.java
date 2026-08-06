class Solution {
    public int countValidPrefixes(String s) {
        int n = s.length();
        int zeroes = 0, ones = 0;
        int validPrefixes = 0;
        for(int i=0;i<n;i++) {
            char ch = s.charAt(i);
            if(ch == '0') zeroes++;
            else ones++;

            if(Math.abs(zeroes - ones) <= 1) validPrefixes++;
        }
        return validPrefixes;
    }
}