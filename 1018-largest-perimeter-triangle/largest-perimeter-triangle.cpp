class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n=nums.size();
        int a,b,c;
        int largestPerm=0;
        sort(nums.begin(),nums.end(),greater<int>());
        for(int i=0;i<n-2;i++)
        {
            a=nums[i];
            b=nums[i+1];
            c=nums[i+2];
            if(a<b+c && b<a+c && c<a+b)
            {
                largestPerm=max(largestPerm,a+b+c);
            }
        }
        return largestPerm;
    }
};