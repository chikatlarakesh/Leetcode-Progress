class Solution {
public:
    bool hasSameDigits(string s) {
        string originalString=s;
        int i;
        while(s.size()>2)
            {
                string result="";
                for(i=0;i<s.size()-1;i++)
                    {
                        int first=s[i]-'0';
                        int second=s[i+1]-'0';
                        int calc=(first+second)%10;
                        result.push_back(calc+'0');
                    }
                s=result;
            }
        if(s[0]==s[1])
        {
            return true;
        }
        return false;
    }
};