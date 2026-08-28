class Solution {
    public boolean isIsomorphic(String s, String t) {
        int n = s.length();

        HashMap<Character,Character> mp = new HashMap<>();
        for(int i=0;i<n;i++) {
            char ch1 = s.charAt(i);
            char ch2 = t.charAt(i);
            if(mp.containsKey(ch1)) {
                if(mp.get(ch1) != ch2) return false;
            }
            else {
                if(mp.containsValue(ch2)) return false;
                mp.put(ch1,ch2);
            }
        }
        return true;
    }
}