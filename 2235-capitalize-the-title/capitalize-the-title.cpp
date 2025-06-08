class Solution {
public:
    string toLowerCase(string& temp)
    {
        int n=temp.length();
        for(int i=0;i<n;i++)
        {
            if(isupper(temp[i])) temp[i]=tolower(temp[i]);
        }
        return temp;
    }
    string convertFirstLetter(string& temp)
    {
        int n=temp.size();
        temp[0]=toupper(temp[0]);
        for(int i=1;i<n;i++)
        {
            if(isupper(temp[i])) temp[i]=tolower(temp[i]);
        }
        return temp;
    }

    string capitalizeTitle(string title) {
        vector<string> words;
        int n=title.length();
        int i;
        string temp="";
        for(char ch:title)
        {
            if(ch==' ')
            {
                words.push_back(temp);
                temp.clear();
            }
            else temp+=ch;
        }
        words.push_back(temp);
        for(string &s: words)
        {
            if((int)s.length()<=2) toLowerCase(s);
            else convertFirstLetter(s);
        }
        string ans="";
        int m=words.size();
        for(i=0;i<m;i++)
        {
            ans+=words[i];
            if(i+1<m) ans+=' ';
        }
        return ans;
    }
};