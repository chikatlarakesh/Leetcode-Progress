class Solution {
public:
    bool checkPrime(int num)
    {
        int n=sqrt(num);
        for(int i=2;i<=n;i++)
        {
            if(num%i==0) return false;
        }
        return true;
    }
    
    bool checkPrimeFrequency(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++) mp[nums[i]]++;
        for(auto it=mp.begin();it!=mp.end();it++)
            {
                if(it->second==1) continue;
                bool ans=checkPrime(it->second);
                if(ans) return true;
            }
        return false;
    }
};