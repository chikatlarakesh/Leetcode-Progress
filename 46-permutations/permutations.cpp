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
            visited[i]=false;
            result.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<int> result;
        vector<vector<int>> ans;
        vector<bool> visited(n,false);
        possPermutations(nums,result,ans,visited);
        return ans;
    }
};