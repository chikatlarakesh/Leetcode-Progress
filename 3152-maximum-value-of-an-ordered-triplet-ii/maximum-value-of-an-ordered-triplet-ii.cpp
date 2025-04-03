class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long first=nums[0],second=INT_MIN,third=INT_MIN;
        int n=nums.size();
        for(int i=1;i<n-1;i++)
        {
            second=max(second,first-nums[i]);
            third=max(third,second*nums[i+1]);
            first=max(first,(long long)nums[i]);

        }
        if(third<0) 
        {
            return 0;
        }
        return third;
    }
};