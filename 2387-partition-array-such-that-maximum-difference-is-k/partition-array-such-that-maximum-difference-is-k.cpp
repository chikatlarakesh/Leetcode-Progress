class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int i=0,j=0,count=0;
        while(i<n)
        {
            if(nums[i]-nums[j]>k)
            {
                count++;
                j=i;
            }
            i++;
        }
        count++;
        return count;
    }
};