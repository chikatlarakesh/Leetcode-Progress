class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        nums[0] = nums[0] - k;
        int prev = nums[0], count = 1;

        for(int i=1;i<n;i++) {
            int minVal = nums[i] - k;
            if(prev < minVal) {
                prev = nums[i] - k;
                count++;
            }
            else if(prev + 1 <= nums[i] + k) {
                prev++;
                count++;
            }
        }
        return count;
    }
};