class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> mp={
            {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}
        };
        int n=s.length();
        int i=0,val=0;
        while(i<n)
        {
            if(i<n && mp[s[i+1]]>mp[s[i]])
            {
                val+=mp[s[i+1]]-mp[s[i]];
                i+=2;
            }
            else
            {
                val+=mp[s[i]];
                i++;
            }
        }
        return val;
    }
};