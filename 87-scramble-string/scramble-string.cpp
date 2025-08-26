class Solution {
public:
    unordered_map<string,bool> mp;

    bool isScramble(string s1, string s2) {
        if(s1.length()!=s2.length()) return false;
        if(s1==s2) return true;
        
        string key=s1+"_"+s2;
        if(mp.find(key)!=mp.end()) return mp[key];

        int n=s1.length();
        bool ans=false;
        for(int i=1;i<n;i++)
        {
            bool swap=isScramble(s1.substr(0,i),s2.substr(n-i,i)) && isScramble(s1.substr(i,n-i),s2.substr(0,n-i));
            bool noSwap=isScramble(s1.substr(0,i),s2.substr(0,i)) && isScramble(s1.substr(i,n-i),s2.substr(i,n-i));
            ans=swap || noSwap;
            if(ans==true) break;
        }
        return mp[key]=ans;
    }
};