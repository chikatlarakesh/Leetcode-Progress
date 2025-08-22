class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> result;
        for(int i=0;i<n;i++)
        {
            while(i>0 && i<n && nums[i]==nums[i-1]) i++;

            int l=i+1,r=n-1;
            while(l<r)
            {
                int sum=nums[i]+nums[l]+nums[r];
                if(sum==0)
                {
                    result.push_back({nums[i],nums[l],nums[r]});
                    l++;
                    r--;
                    while(l<n && nums[l]==nums[l-1]) l++;
                    while(r>=0 && nums[r]==nums[r+1]) r--;
                }
                else if(sum<0) l++;
                else r--;
            }
        }
        return result;
    }
};