class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int> m;
        int n=nums.size();
        int i,ans;
        for(i=0;i<n;i++)
        {
            if(m[nums[i]]>0)
            {
                ans=nums[i];
                break;
            }
            m[nums[i]]++;
        }
        return ans;
    }
};