class Solution {
public:
    string largestOddNumber(string num) {
        string s=num;
        int n=s.length();
        for(int i=n-1;i>=0;i--)
        {
            int num=s[i]-'0';
            if(num%2==1) return s;
            s.pop_back();
        }

        string result="";
        char ans='0';
        for(char ch:num)
        {
            if(ch-'0'%2==1 && ch>ans) ans=ch;
        }
        if(ans!='0') result+=ans;
        return result;
    }
};