class Solution {
public:
    bool isValid(string word) {
        if(word.length()<3) return false;
        int validChar=0,vowels=0,consonants=0;
        string allVowels="AEIOUaeiou";
        for(char ch:word)
        {
            if(isupper(ch) || islower(ch) || isdigit(ch)) validChar++;
            else return false;
            if(allVowels.find(ch)!=string::npos) vowels++;
            else if(!isdigit(ch)) consonants++;
        }

        if(vowels>0 && consonants>0) return true;
        return false;
    }
};