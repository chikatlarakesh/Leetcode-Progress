class Solution {
    public boolean isVowel(char ch) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || 
    ch == 'o' || ch == 'u') return true;
    return false;
    }

    public String trimTrailingVowels(String s) {
        int n = s.length();
        int i=n-1;
        while(i >= 0 && isVowel(s.charAt(i))) {
            i--;
        }
        if(i >=0) return s.substring(0,i+1);
        return "";
    }
}