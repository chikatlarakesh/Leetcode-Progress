class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        // int n=nums.size();
        // int i=0;
        long long count=0,sum=0;
        for(int num: nums)
        {
            if(num==0)
            {
                count++;
                sum+=count;
            }
            else count=0;
        }
        // while(i<n)
        // {
        //     while(i<n && nums[i]!=0)
        //     {
        //         i++;
        //     }
        //     count=0;
        //     while(i<n && nums[i]==0)
        //     {
        //         i++;
        //         count++;
        //     }
        //     sum+=(count*(count+1))/2;
        // }
        return sum;
    }
};