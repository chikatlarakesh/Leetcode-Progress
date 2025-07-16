class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int> result(n,0);

        for(int i=1;i<n;i++)
        {
            result[i]=nums[i-1]+result[i-1];
        }
        int sum=0;
        for(int i=n-2;i>=0;i--)
        {
            sum+=nums[i+1];
            result[i]=abs(result[i]-sum);
        }
        return result;
    }
};