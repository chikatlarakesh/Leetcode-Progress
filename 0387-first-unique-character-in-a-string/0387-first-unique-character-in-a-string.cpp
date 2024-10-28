class Solution {
public:
    int firstUniqChar(string s) {
        int n =s.length();
        map<char,int> m;
        int i;
        int result=-1;
        for(i=0;i<n;i++)
        {
            m[s[i]]++;
        }
        for(i=0;i<n;i++)
        {
            if(m[s[i]]==1)
            {
                result=i;
                break;
            }
        }
        return result;
    }
};