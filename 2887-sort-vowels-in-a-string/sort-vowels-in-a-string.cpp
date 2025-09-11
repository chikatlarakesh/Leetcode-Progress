class Solution {
public:
    string sortVowels(string s) {
        string vowels="AEIOUaeiou";
        string t="";
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            if(vowels.find(s[i])!=string::npos)
            {
                t+=s[i];
                s[i]='.';
            }
        }
        if(t.empty()) return s;
        sort(t.begin(),t.end());

        int i=0,j=0;
        while(i<n)
        {
            while(i<n && s[i]!='.') i++;
            s[i]=t[j];
            j++;
            i++;
        }
        return s;
    }
};