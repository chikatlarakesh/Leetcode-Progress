class Solution {
public:
    bool doesAliceWin(string s) {
        int vowelCount=0;
        string vowels="aeiou";
        for(char ch:s)
        {
            if(vowels.find(ch)!=string::npos) vowelCount++;
        }
        if(vowelCount==0) return false;
        return true;
    }
};