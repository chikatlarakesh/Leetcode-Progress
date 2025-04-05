class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int res=0;
        for(int &num:nums){
            res |= num;
        }
        return res<<(n-1);
    }
};