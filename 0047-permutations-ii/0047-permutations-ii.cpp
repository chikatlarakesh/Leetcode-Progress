class Solution {
public:
    void posPermute(int ind,int n,vector<int>& nums,vector<int>& res,unordered_set<int>& s,vector<vector<int>>& result)
    {
        if(res.size()==n)
        {
            result.push_back(res);
            return;
        }
        for(int i=0;i<n;i++)
        {
            if(s.find(i)==s.end())
            {
                res.push_back(nums[i]);
                s.insert(i);
                posPermute(i+1,n,nums,res,s,result);
                res.pop_back();
                s.erase(i);
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> result;
        vector<int> res;
        unordered_set<int> s;
        posPermute(0,n,nums,res,s,result);
        set<vector<int>> duplicates(result.begin(),result.end());
        vector<vector<int>> ans(duplicates.begin(),duplicates.end());
        return ans;
    }
};