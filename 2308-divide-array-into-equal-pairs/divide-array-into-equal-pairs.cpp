class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int> m;
        int n=nums.size();
        int i;
        for(i=0;i<n;i++)
        {
            m[nums[i]]++;
        }
        int count=0;
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