class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n=nums.size();
        int l=0,maxScore=0,sum=0;
        for(int r=0;r<n;r++)
        {
            while(mp.find(nums[r])!=mp.end())
            {
                sum-=nums[l];
                mp[nums[l]]--;
                if(mp[nums[l]]==0) mp.erase(nums[l]);
                l++;
            }
            mp[nums[r]]++;
            sum+=nums[r];
            maxScore=max(maxScore,sum);
        }
        maxScore=max(maxScore,sum);
        return maxScore;
    }
};