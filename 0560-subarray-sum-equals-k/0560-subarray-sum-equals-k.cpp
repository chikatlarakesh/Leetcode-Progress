class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> m;
        m[0]=1;
        int n=nums.size();
        int i;
        int sum=0;
        int count=0;
        for(i=0;i<n;i++)
        {
            sum= sum +nums[i];
            int remove = sum-k;
            count=count+ m[remove];
            m[sum]=m[sum]+1;
        }
        return count;
    }
};