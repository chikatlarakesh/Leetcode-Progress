class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==1) return 0;
        sort(nums.begin(),nums.end());
        int minLength=INT_MAX;

        for(int i=0;i<n;i++)
            {
                long long val=1LL*nums[i]*k;
                int j=upper_bound(nums.begin(),nums.end(),val)-nums.begin()-1;
                int size=j-i+1;
                minLength=min(minLength,n-size);
            }
        return minLength;
    }
};