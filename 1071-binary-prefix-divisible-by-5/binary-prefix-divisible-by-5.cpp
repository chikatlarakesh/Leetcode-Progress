class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size();
        vector<bool> result(n,false);
        int bVal = 0;
        for(int i=0;i<n;i++) {
            bVal = ((bVal * 2) + nums[i]) % 5;
            if(bVal % 5 == 0) result[i] = true;
        }
        return result;
    }
};