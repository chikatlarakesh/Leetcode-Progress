class Solution {
public:
    vector<vector<int>> possible(int i,vector<int> &result, vector<int> &nums)
    {
        int n=nums.size();
        if(i==n)
        {
            return {result};
        }
        result.push_back(nums[i]);
        vector<vector<int>> l=possible(i+1,result,nums);
        result.pop_back();
        vector<vector<int>> r=possible(i+1,result,nums);
        l.insert(l.end(),r.begin(),r.end());
        return l;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> result;
        return possible(0,result,nums);
    }
};