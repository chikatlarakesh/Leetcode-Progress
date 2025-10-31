class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        using ll = long long;
        int n = nums.size();

        ll operations = abs(target[0] - nums[0]);
        for(int i=1;i<n;i++) {
            int prev = target[i-1] - nums[i-1];
            int curr = target[i] - nums[i];

            if((prev < 0 && curr > 0) || (prev > 0 && curr < 0)) {
                operations += abs(curr);
            }
            else if(abs(curr) > abs(prev)) {
                operations += (abs(curr) - abs(prev));
            }
        }
        return operations;
    }
};