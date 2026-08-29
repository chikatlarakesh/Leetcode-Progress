class Solution {
    public boolean isIsomorphic(String s, String t) {
        int n = s.length();

        int[] sMap = new int[256];
        int[] tMap = new int[256];

        for(int i=0;i<n;i++) {
            int sIndex = s.charAt(i);
            int tIndex = t.charAt(i);
            
            if((sMap[sIndex] > 0 && sMap[sIndex] != tIndex + 1) || 
                (tMap[tIndex] > 0 && tMap[tIndex] != sIndex + 1)) {
                    return false;
                }
            else {
                sMap[sIndex] = tIndex + 1;
                tMap[tIndex] = sIndex + 1;
            }
        }
        return true;
    }
}