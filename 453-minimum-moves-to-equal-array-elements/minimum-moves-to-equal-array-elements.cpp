class Solution {
public:
    int minMoves(vector<int>& nums) {
        if(nums.size()==1) return 0;
        int count=0;
        int smallest=*min_element(nums.begin(),nums.end());
        for(int num:nums)
        {
            if(num>smallest) count+=num-smallest;
        }
        return count;
    }
};