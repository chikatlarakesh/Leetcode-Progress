class Solution {
public:
    void possCombinations(int i,int k,int n,vector<int>& result,vector<vector<int>>& ans,int sum)
    {
        if(sum>=n || k<=0 || i==10)
        {
            if(sum==n && k==0) ans.push_back(result);
            return;
        }

        result.push_back(i);
        possCombinations(i+1,k-1,n,result,ans,sum+i);
        result.pop_back();
        possCombinations(i+1,k,n,result,ans,sum);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> result;
        vector<vector<int>> ans;
        possCombinations(1,k,n,result,ans,0);
        return ans;
    }
};