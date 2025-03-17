class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int num: nums)
        {
            m[num]++;
        }
        for(auto it=m.begin();it!=m.end();it++)
        {
            if(it->second%2==1)
            {
                return false;
            }
        }
        return true;
    }
};