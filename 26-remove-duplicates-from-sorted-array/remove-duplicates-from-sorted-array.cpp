class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int k=1,j=1;
        for(int i=1;i<n;i++)
        {
            if(nums[i]!=nums[i-1])
            {
                k++;
                nums[j]=nums[i];
                j++;
            } 
        }
        return k;
    }
};