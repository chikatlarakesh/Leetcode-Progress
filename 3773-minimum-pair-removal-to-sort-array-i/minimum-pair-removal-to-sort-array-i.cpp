class Solution {
public:
    int findMinSum(vector<int>& nums) {
        int n = nums.size();
        int minSum = INT_MAX;
        int index = -1;

        for(int i=0;i<n-1;i++) {
            if(nums[i] + nums[i+1] < minSum) {
                minSum = nums[i] + nums[i+1];
                index = i;
            }
        }
        return index;
    }

    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        int ops = 0;

        while(!is_sorted(nums.begin(),nums.end())) {
            int index = findMinSum(nums);
            nums[index] = nums[index] + nums[index+1];
            nums.erase(nums.begin() + index+1);
            ops++;
        }
        return ops;
    }
};