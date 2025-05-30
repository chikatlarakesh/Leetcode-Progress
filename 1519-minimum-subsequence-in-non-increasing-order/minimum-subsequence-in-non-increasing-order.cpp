class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        int total=accumulate(nums.begin(),nums.end(),0);
        sort(nums.begin(),nums.end(),greater<int>());
        int n=nums.size();
        vector<int> result;
        int sum=0;
        for(int num:nums)
        {
            sum+=num;
            result.push_back(num);
            int diff=total-sum;
            if(sum>diff)
            {
                break;
            }
        }
        return result;
    }
};