class Solution {
public:
    int atmost(vector<int>& nums, int k)
    {
        int n=nums.size();
        int l=0;
        int r;
        int result=0;
        unordered_map<int,int> m;
        for(r=0;r<n;r++)
        {
            m[nums[r]]++;
            while(m.size()>k)
            {
                m[nums[l]]--;
                if(m[nums[l]]==0)
                {
                    m.erase(nums[l]);
                }
                l++;
            }
            result=result+(r-l+1);
        }
        return result;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int ans = atmost(nums,k)-atmost(nums,k-1);
        return ans;
    }
};