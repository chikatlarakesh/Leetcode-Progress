class Solution {
public:
    string processStr(string s) {
        string result="";
        for(char ch:s)
            {
                if(ch>='a' && ch<='z')
                {
                    result+=ch;
                }
                else if(ch=='*')
                {
                    if(!result.empty()) result.pop_back();
                }
                else if(ch=='#')
                {
                    result+=result;
                }
                else reverse(result.begin(),result.end());
            }
        return result;
    }
};