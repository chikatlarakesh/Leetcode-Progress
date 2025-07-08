class Solution {
public:
    void possPermutations(vector<int>& nums,vector<int>& result,vector<vector<int>>& ans,vector<bool>& visited)
    {
        if(result.size()==nums.size())
        {
            ans.push_back(result);
            return;
        }

        for(int i=0;i<nums.size();i++)
        {
            if(visited[i]==true) continue;
            visited[i]=true;
            result.push_back(nums[i]);
            possPermutations(nums,result,ans,visited);
            result.pop_back();
            visited[i]=false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> result;
        vector<vector<int>> ans;
        vector<bool> visited(nums.size(),false);
        possPermutations(nums,result,ans,visited);
        return ans;
    }
};