class Solution {
    public String minWindow(String s, String t) {
        int n = s.length();
        int m = t.length();
        int[] hash = new int[256];

        for(char ch : t.toCharArray()) {
            hash[ch]++;
        }

        int l = 0, startIndex = -1;
        int minLen = Integer.MAX_VALUE, count = 0;
        for(int r=0;r<n;r++) {
            char ch = s.charAt(r);
            if(hash[ch] > 0) count++;
            hash[ch]--;

            while(count == m) {
                if(r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    startIndex = l;
                }

                hash[s.charAt(l)]++;
                if(hash[s.charAt(l)] > 0) count--;
                l++;
            }
        }
        if(startIndex == -1) return "";
        else return s.substring(startIndex,startIndex + minLen);
    }
}