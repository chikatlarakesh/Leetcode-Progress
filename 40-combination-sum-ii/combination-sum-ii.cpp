class Solution {
public:
    void possCombinations(int ind,int n,vector<int>& vec,int target,      vector<int>& arr,vector<vector<int>>& result)
    {
        if(target<=0 || ind==n)
        {
            if(target==0) result.push_back(arr);
            return;
        }
        for(int i=ind;i<n;i++)
        {
            if(i>ind && vec[i]==vec[i-1]) continue;
            if(vec[i]>target) break;
            arr.push_back(vec[i]);
            possCombinations(i+1,n,vec,target-vec[i],arr,result);
            arr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        int n=candidates.size();
        vector<vector<int>> result;
        vector<int> arr;
        possCombinations(0,n,candidates,target,arr,result);
        return result;
    }
};