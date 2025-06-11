class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> positives;
        vector<int> negatives;
        for(int num:nums)
        {
            if(num>0) positives.push_back(num);
            else negatives.push_back(num);
        }
        int n=nums.size();
        int j=0,k=0;
        for(int i=0;i<n;i++)
        {
            if(i%2==0) 
            {
                nums[i]=positives[j];
                j++;
            }
            else
            {
                nums[i]=negatives[k];
                k++;
            }
        }
        return nums;
    }
};