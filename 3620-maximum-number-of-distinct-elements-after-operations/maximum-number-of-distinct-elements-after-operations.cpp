class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 1;
        sort(nums.begin(),nums.end());
        nums[0] = nums[0] - k;

        for(int i=1;i<n;i++) {
            int bound = nums[i] + k;
            if(nums[i-1] < nums[i] - k) {
                nums[i] = nums[i] - k;
                count++;
            }
            else {
                int bound = nums[i] + k;
                if(nums[i-1] + 1 <= bound) {
                    nums[i] = nums[i-1] + 1;
                    count++;
                }
                else nums[i] = nums[i-1];
            }
        }
        return count;
    }
};