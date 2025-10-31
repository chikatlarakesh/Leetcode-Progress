class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n = target.size();

        int operations = target[0];
        for(int i=1;i<n;i++) {
            int prev = target[i-1];
            int curr = target[i];

            if(curr > prev) {
                operations += curr - prev;
            }
        }
        return operations;
    }
};