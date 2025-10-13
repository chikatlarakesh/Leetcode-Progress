class Solution {
public:
    void nextSmaller(vector<int>& nums,vector<int>& nse) {
        int n = nums.size();
        stack<int> st;
        st.push(n-1);

        for(int i=n-2;i>=0;i--) {
            while(!st.empty() && nums[st.top()] >= nums[i]) st.pop();
            if(!st.empty()) nse[i] = st.top();
            st.push(i);
        }
    }

    void prevSmaller(vector<int>& nums,vector<int>& pse) {
        int n = nums.size();
        stack<int> st;
        st.push(0);

        for(int i=1;i<n;i++) {
            while(!st.empty() && nums[st.top()] >= nums[i]) st.pop();
            if(!st.empty()) pse[i] = st.top();
            st.push(i);
        }
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if(n == 1) return heights[0];
        vector<int> nse(n,n), pse(n,-1);
        nextSmaller(heights,nse);
        prevSmaller(heights,pse);

        int maxArea = 0;
        for(int i=0;i<n;i++) {
            int left = abs(nse[i] - i) * heights[i];
            int right = abs(pse[i] - i) * heights[i];
            int area = left + right - heights[i];
            maxArea = max(maxArea,area);
            // if(nse[i] != -1) {
            //     int area = abs(nse[i] - i) * heights[i];
            //     maxArea = max(area,maxArea);
            // }
            // if(pse[i] != -1) {
            //     int area = abs(pse[i] - i) * heights[i];
            //     maxArea = max(area,maxArea);
            // }
        }
        return maxArea;

    }
};