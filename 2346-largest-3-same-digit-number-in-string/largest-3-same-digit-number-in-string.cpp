class Solution {
public:
    string largestGoodInteger(string num) {
        int n=num.length();
        string ans="";
        char ch='0';
        for(int i=0;i<n-2;i++)
        {
            if(num[i]>=ch && num[i]==num[i+1] && num[i+1]==num[i+2])
            {
                ch=num[i];
                ans="";
                for(int j=0;j<3;j++) ans+=num[i];
            }
        }
        return ans;
    }
};