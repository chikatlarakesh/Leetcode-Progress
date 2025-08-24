class Solution {
public:
    string reverseWords(string s) {
        while(s.back()==' ') s.pop_back();
        reverse(s.begin(),s.end());
        while(s.back()==' ') s.pop_back();
        reverse(s.begin(),s.end());

        int n=s.length();
        string ans="";
        int i=n-1;
        while(i>=0)
        {
            string temp="";
            while(i>=0 && s[i]!=' ')
            {
                temp+=s[i];
                i--;
            }
            while(i>=0 && s[i]==' ') i--;
            reverse(temp.begin(),temp.end());
            ans+=temp;
            if(i!=-1) ans+=' ';
        }
        return ans;
        
    }
};