class Solution {
public:
    int countSubsets(int i,int currOR,int maxOR,vector<int>& nums)
    {
        if(i==0)
        {
            int take=((currOR | nums[i])==maxOR);
            int notTake=currOR==maxOR;
            return take+notTake;
        }

        int take=countSubsets(i-1,currOR | nums[i],maxOR,nums);
        int notTake=countSubsets(i-1,currOR,maxOR,nums);
        return take+notTake;
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int n=nums.size();
        int maxOR=0;
        for(int num:nums)
        {
            maxOR=maxOR | num;
        }
        return countSubsets(n-1,0,maxOR,nums);
    }
};