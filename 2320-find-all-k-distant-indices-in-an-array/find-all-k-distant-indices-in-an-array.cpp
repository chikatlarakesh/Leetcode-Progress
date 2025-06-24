class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> keyIndices;
        vector<int> result;
        int n=nums.size();
        int i,j,lastSeen;
        for(i=0;i<n;i++)
        {
            if(nums[i]==key) keyIndices.push_back(i);
        }
        int m=keyIndices.size();
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(abs(i-keyIndices[j])<=k)
                {
                    result.push_back(i);
                    break;
                }
            }
        }
        return result;
    }
};