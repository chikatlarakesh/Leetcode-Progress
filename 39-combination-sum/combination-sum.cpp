class Solution {
public:
    void possCombinations(int i,int n,vector<int>& vec,int target,vector<int>& arr,vector<vector<int>>& result)
    {
        if(target<=0 || i==n)
        {
            if(target==0) result.push_back(arr);
            return;
        }
        arr.push_back(vec[i]);
        possCombinations(i,n,vec,target-vec[i],arr,result);
        arr.pop_back();
        possCombinations(i+1,n,vec,target,arr,result);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();
        vector<vector<int>> result;
        vector<int> arr;
        possCombinations(0,n,candidates,target,arr,result);
        return result;
    }
};