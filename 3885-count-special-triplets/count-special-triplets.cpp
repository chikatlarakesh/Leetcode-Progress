class Solution {
public:
    const int MOD = 1e9 + 7;
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> left, right;
        for(int num : nums) right[num]++;

        int triplets = 0;
        for(int i=0;i<n;i++) {
            right[nums[i]]--;
            int leftCount = left[2 * nums[i]];
            int rightCount = right[2 * nums[i]];

            triplets = (triplets + (1LL * leftCount * rightCount)) % MOD;
            left[nums[i]]++;
        }
        return triplets;
    }
};