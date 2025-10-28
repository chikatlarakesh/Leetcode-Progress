class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(),nums.end(),0);
        int count = 0, leftSum = 0;

        for(int i=0;i<n;i++) {
            leftSum += nums[i];
            int rightSum = totalSum - leftSum;

            if(nums[i] == 0) {
                if(leftSum == rightSum) count += 2;
                else if(abs(leftSum - rightSum) == 1) count++;
            }
        }
        return count;
    }
};