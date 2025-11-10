class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ops = 0;
        stack<int> st;

        for(int i=0;i<n;i++) {
            while(!st.empty() && st.top() > nums[i]) {
                st.pop();
            }
            
            if(nums[i] == 0) continue;
            if(st.empty() || st.top() < nums[i]) {
                ops++;
                st.push(nums[i]);
            }
        }
        return ops;
    }
};