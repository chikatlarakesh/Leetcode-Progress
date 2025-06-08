class Solution {
public:
    bool detectCapitalUse(string word) {
        int n=word.length();
        int capitalCount=0;
        for(char ch: word) if(isupper(ch)) capitalCount++;
        if(capitalCount==0 || capitalCount==n) return true;
        if(capitalCount==1 && isupper(word[0])) return true;
        return false;
    }
};