typedef long long ll;
class Solution {
public:
    ll countLessEqual(vector<int>& nums1, vector<int>& nums2, ll x) {
        int n = nums1.size(), m = nums2.size();
        ll count = 0;

        for (int i = 0; i < n; ++i) {
            int a = nums1[i];
            if (a == 0) {
                if (x >= 0) count += m;
            } else if (a > 0) {
                int low = 0, high = m - 1, res = -1;
                while (low <= high) {
                    int mid = (low + high) / 2;
                    if ((ll)a * nums2[mid] <= x) {
                        res = mid;
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                }
                count += (res + 1);
            } else {
                int low = 0, high = m - 1, res = m;
                while (low <= high) {
                    int mid = (low + high) / 2;
                    if ((ll)a * nums2[mid] <= x) {
                        res = mid;
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                }
                count += (m - res);
            }
        }
        return count;
    }

    ll kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        ll low = -1e10, high = 1e10, ans = 0;
        while (low <= high) {
            ll mid = low + (high - low) / 2;
            if (countLessEqual(nums1, nums2, mid) >= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};