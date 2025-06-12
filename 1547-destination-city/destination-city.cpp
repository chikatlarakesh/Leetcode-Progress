class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        if(paths.size()==1) return paths[0][1];
        int n=paths.size();
        string ans="";
        unordered_map<string,int> mp;
        for(int i=0;i<n;i++)
        {   
            if(mp.find(paths[i][0])!=mp.end())
            {
                mp.erase(paths[i][0]);
            }
            else mp[paths[i][0]]=0;
            if(mp.find(paths[i][1])!=mp.end())
            {
                mp.erase(paths[i][1]);
            }
            else mp[paths[i][1]]=1;
        }
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            if(it->second==1)
            {
                ans=it->first;
                break;
            }
        }
        return ans;
    }
};