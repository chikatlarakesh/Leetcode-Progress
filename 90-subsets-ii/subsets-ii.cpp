class Solution {
public:
    void possSubsets(vector<int>& nums,int i,int n,vector<vector<int>>& ans,vector<int>& result)
    {
        if(i==n)
        {
            ans.push_back(result);
            return;
        }
        result.push_back(nums[i]);
        possSubsets(nums,i+1,n,ans,result);
        result.pop_back();

        int ind=i+1;
        while(ind<n && nums[ind]==nums[ind-1]) ind++;
        possSubsets(nums,ind,n,ans,result);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> result;
        vector<vector<int>> ans;
        possSubsets(nums,0,n,ans,result);
        return ans;
    }
};