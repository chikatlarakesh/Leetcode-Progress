class Solution {
public:
    bool containsZero(int num) {
        while (num > 0) {
            if (num % 10 == 0) return true;
            num /= 10;
        }
        return false;
    }

    vector<int> getNoZeroIntegers(int n) {
        for (int i = 1; i < n; i++) {
            int j = n - i;
            if (!containsZero(i) && !containsZero(j)) {
                return {i, j};
            }
        }
        return {};
    }
};