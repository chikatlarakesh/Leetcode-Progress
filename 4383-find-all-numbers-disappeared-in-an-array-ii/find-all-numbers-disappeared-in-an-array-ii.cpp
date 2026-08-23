class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> result;
        int start = lower;

        for(int i = 0; i < n; i++) {
            if(nums[i] < start) continue;
            if(nums[i] > upper) break;
            if(nums[i] > start) {
                int end = nums[i] - 1;
                result.push_back({start, end});
            }

            start = nums[i] + 1;
        }

        if(start <= upper) {
            result.push_back({start, upper});
        }

        return result;
    }
};