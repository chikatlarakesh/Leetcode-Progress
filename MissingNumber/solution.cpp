int missingNumber(vector<int>& nums) 
{
        int result=0;
        int n=nums.size();
        int i;
        for(i=0;i<=n;i++)
        {
            result=result^i;
        }
        for(int num : nums)
        {
            result=result^num;
        }
        return result;
}
