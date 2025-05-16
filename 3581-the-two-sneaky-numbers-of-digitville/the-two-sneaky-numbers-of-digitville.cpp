class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int val1=-1,val2=-1;
        unordered_map<int,int> m;
        for(int num:nums) m[num]++;
        for(auto it=m.begin();it!=m.end();it++)
        {
            if(it->second==2)
            {
                if(val1==-1) val1=it->first;
                else if(val2==-1) val2=it->first;
            }
            if(val2!=-1) break;
        }
        return {val1,val2};
    }
};