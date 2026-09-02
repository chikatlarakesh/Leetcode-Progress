class Solution {
    public int characterReplacement(String s, int k) {
        int n = s.length();
        int l = 0, maxFreq = 0, maxLength = 0;
        int[] hash = new int[26];

        for(int r = 0;r < n; r++) {
            int index = s.charAt(r) - 'A';
            hash[index]++;
            maxFreq = Math.max(maxFreq,hash[index]);
            int length = r - l + 1;

            if(length - maxFreq > k) {
                hash[s.charAt(l) - 'A']--;
                l++;
            }

            if(length - maxFreq <= k) {
                maxLength = Math.max(maxLength,length);
            }
        }
        return maxLength;
    }
}