class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int i=0,j=n-1;
        int minimizedSum=INT_MIN;
        while(i<j)
        {
            int sum=nums[i]+nums[j];
            minimizedSum=max(minimizedSum,sum);
            i++;
            j--;
        }
        return minimizedSum;
    }
};