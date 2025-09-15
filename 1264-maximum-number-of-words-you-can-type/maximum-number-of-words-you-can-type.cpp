class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int n = text.length();
        int totalWords = 0;
        bool flag = true;
        for(int i=0;i<n;i++)
        {
            if(brokenLetters.find(text[i]) != string::npos) flag = false;
            if(text[i]==' ' && flag == true) totalWords++;
            else if(text[i]==' ' &&  flag == false) flag = true;
        }
        if(flag == true) totalWords++;
        return totalWords;
    }
};