class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int> m;
        int n=s.length();
        for(char ch: s)
            {
                m[ch]++;
            }
        int odd=0,even=INT_MAX;
        for(auto it=m.begin();it!=m.end();it++)
            {
                if(it->second%2!=0)
                {
                    odd=max(odd,it->second);
                }
                if(it->second%2==0)
                {
                    even=min(even,it->second);
                }
            }
        if(even==INT_MAX)
        {
            even=0;
        }
        return odd-even;
    }
};