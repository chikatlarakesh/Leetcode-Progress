class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int freq=n/3,val=nums[0],count=1;
        vector<int> result;

        for(int i=1;i<n;i++)
        {
            if(val!=nums[i]) 
            {
                if(count>freq) result.push_back(val);
                val=nums[i];
                count=1;
            }
            else count++;
        }
        if(count>freq) result.push_back(val);
        return result;
    }
};