class Solution {
public:
    // void posSSets(int i,vector<int>& nums,vector<int>& res,vector<vector<int>> &result)
    // {
    //     int n=nums.size();
    //     if(i==n)
    //     {
    //         result.push_back(res);
    //         return;
    //     }
    //     res.push_back(nums[i]);
    //     posSSets(i+1,nums,res,result);
    //     res.pop_back();
    //     posSSets(i+1,nums,res,result);
    // }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        // posSSets(0,nums,res,result);
        int n=nums.size();
        int subSets=1<<n;
        for(int num=0;num<subSets;num++)
        {
            vector<int> res;
            for(int j=0;j<n;j++)
            {
                if(num&(1<<j))
                {
                    res.push_back(nums[j]);
                }
            }
            result.push_back(res);
        }
        return result;
    }
};