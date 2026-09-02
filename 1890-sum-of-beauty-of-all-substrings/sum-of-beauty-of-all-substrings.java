class Solution {
    public int beautySum(String s) {
        int n = s.length();
        int sum = 0;

        for(int i=0;i<n;i++) {
            int[] hash = new int[26];
            for(int j=i;j<n;j++) {
                int index = s.charAt(j) - 'a';
                hash[index]++;
                int maxFreq = hash[index];
                int minFreq = hash[index];

                for(int k=0;k<26;k++) {
                    maxFreq = Math.max(maxFreq,hash[k]);
                    if(hash[k] > 0) minFreq = Math.min(minFreq,hash[k]);
                }
                sum += (maxFreq - minFreq);
            }
        }
        return sum;
    }
}