class Solution {
public:
    void possPermutations(int ind,int n,vector<int>& nums,vector<int>& result,vector<vector<int>>& ans)
    {
        if(ind==n)
        {
            ans.push_back(result);
            return;
        }
        for(int i=ind;i<n;i++)
        {
            swap(result[i],result[ind]);
            possPermutations(ind+1,n,nums,result,ans);
            swap(result[i],result[ind]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<int> result=nums;
        vector<vector<int>> ans;
        possPermutations(0,n,nums,result,ans);
        return ans;
    }
};