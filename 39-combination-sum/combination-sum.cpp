class Solution {
public:
    void uniqueCombinations(int i,int target,vector<int>& vec,vector<vector<int>>& result,vector<int>& nums)
    {
        if(target<=0 || i==nums.size())
        {
            if(target==0) result.push_back(vec);
            return;
        }

        vec.push_back(nums[i]);
        uniqueCombinations(i,target-nums[i],vec,result,nums);
        vec.pop_back();
        uniqueCombinations(i+1,target,vec,result,nums);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();
        vector<int> vec;
        vector<vector<int>> result;
        uniqueCombinations(0,target,vec,result,candidates);
        return result;
    }
};