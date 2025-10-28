class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        using ll = long long;
        int n = nums1.size();
        ll operations = 1;
        int lastVal = nums2[n];
        for(int i=0;i<n;i++) {
            operations += abs(nums1[i] - nums2[i]);
        }

        int mini = 1e9;
        for(int i=0;i<n;i++) {
            int l = min(nums1[i],nums2[i]);
            int r = max(nums1[i],nums2[i]);

            if(lastVal < l) {
                mini = min(mini, l - lastVal);
            }
            else if(lastVal > r) {
                mini = min(mini, lastVal - r);
            }
            else {
                mini = 0;
                break;
            }
        }
        operations += mini;
        return operations;
    }
};