class Solution {
public:
    int numDifferentIntegers(string word) {
        int n=word.length();
        string s="",zeroes="";
        unordered_map<string,int> mp;
        for(int i=0;i<n;i++)
        {
            if(word[i]=='0' && !mp.count("0") && s.empty()) zeroes+=word[i];
                else if(islower(word[i]))
                {
                    if(!zeroes.empty()) mp["0"]++;
                    zeroes=""; 
                }
                else
                {
                    zeroes="";
                }
            if(isdigit(word[i])) 
            {
                //if(word[i]=='0' && s.length()==0) zeroes+=word[i];
                //else if(word[i]>='1' && word[i]<='9') zeroes="";
                if(word[i]=='0' && s.length()==0) continue;
                else s+=word[i];
            }
            else
            {
                if(!s.empty())
                {
                    mp[s]++;
                }
                s="";
            }
        }
        if(!s.empty())
        {
            mp[s]++;
        } 
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            cout<<"NUM "<<it->first<<" ";
        }
        if(!zeroes.empty()) mp["0"]++;
        int ans=mp.size();
        return ans;
    }
};