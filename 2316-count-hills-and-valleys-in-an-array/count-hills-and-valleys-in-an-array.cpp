class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n=nums.size();
        stack<int> st;
        vector<int> prefix(n,0);
        vector<int> suffix(n,0);
        st.push(nums[0]);
        for(int i=1;i<n-1;i++)
        {
            while(!st.empty() && st.top()==nums[i]) st.pop();
            if(!st.empty() && st.top()!=nums[i])
            {
                prefix[i]=st.top();
            }
            st.push(nums[i]);
        }

        while(!st.empty()) st.pop();
        st.push(nums[n-1]);
        for(int i=n-2;i>=1;i--)
        {
            while(!st.empty() && st.top()==nums[i]) st.pop();
            if(!st.empty() && st.top()!=nums[i])
            {
                suffix[i]=st.top();
            }
            st.push(nums[i]);
        }

        int count=0;
        for(int i=1;i<n-1;i++)
        {
            if(nums[i]==nums[i-1]) continue;
            if(prefix[i]==0 || suffix[i]==0) continue;
            if((nums[i]>prefix[i] && nums[i]>suffix[i]) || (nums[i]<prefix[i] && nums[i]<suffix[i])) count++;
        }
        return count;
    }
};