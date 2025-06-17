class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> result;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int l=0,r=2;
        while(r<n)
        {
            if(nums[r]-nums[l]>k) return result;
            l+=3;
            r+=3;
        }
        int m=n/3;
        for(int i=0;i<m;i++)
        {
            vector<int> vec;
            for(int j=i*3;j<i*3+3;j++)
            {
                vec.push_back(nums[j]);
            }
            result.push_back(vec);
        }
        return result;
    }
};