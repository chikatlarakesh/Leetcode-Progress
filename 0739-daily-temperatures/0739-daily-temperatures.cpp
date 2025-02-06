class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result;
        unordered_map<int,int> m;
        int i;
        int n=temperatures.size();
        for(i=n-1;i>=0;i--)
        {
            int ind=INT_MAX,count=0;
            for(auto it=m.begin();it!=m.end();it++)
            {
                if(!m.empty() && it->first>temperatures[i])
                {
                    ind=min(ind,it->second);
                    count++;
                }           
            }
            if(ind!=INT_MAX)
            {
                result.push_back(ind-i);
            }
            m[temperatures[i]]=i;
            if(count==0)
            {
                result.push_back(0);
            }
        }
        reverse(result.begin(),result.end());
        return result;
    }
};