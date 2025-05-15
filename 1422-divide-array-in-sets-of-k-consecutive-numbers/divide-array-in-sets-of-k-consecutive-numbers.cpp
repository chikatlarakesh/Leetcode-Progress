class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n=nums.size();
        if(n%k!=0) return false;
        map<int,int> m;
        for(int num:nums) m[num]++;
        while(!m.empty())
        {
            int start=m.begin()->first;
            for(int i=0;i<k;i++)
            {
                if(m[start+i]==0) return false;
                m[start+i]--;
                if(m[start+i]==0) m.erase(start+i);
                
            }
        }
        return true;
    }
};