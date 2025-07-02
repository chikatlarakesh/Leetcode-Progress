class Solution {
public:
    void possSubsets(vector<int>& nums,int n,int i,vector<int>& vec,vector<vector<int>>& result)
    {
        if(i==n)
        {
            result.push_back(vec);
            return;
        }
        vec.push_back(nums[i]);
        possSubsets(nums,n,i+1,vec,result);
        vec.pop_back();
        possSubsets(nums,n,i+1,vec,result);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<int> vec;
        vector<vector<int>> result;
        possSubsets(nums,n,0,vec,result);
        return result;
    }
};