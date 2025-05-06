class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size();
        stack<int> st;
        int i;
        for(i=0;i<n;i++)
        {
            if(asteroids[i]>0) st.push(asteroids[i]);
            else
            {
                if(!st.empty() && st.top()<0) 
                {
                    st.push(asteroids[i]);
                    continue;
                }
                int absValue=abs(asteroids[i]);
                while(!st.empty() && st.top()>0 && st.top()<absValue)
                {
                    st.pop();
                }
                if(!st.empty() && st.top()>0 && abs(st.top())==absValue)
                {
                    st.pop();
                    continue;
                }
                if(st.empty() || st.top()<0) st.push(asteroids[i]);
            }
        }
        vector<int> finalState;
        if(st.empty()) return finalState;
        else
        {
            while(!st.empty())
            {
                finalState.push_back(st.top());
                st.pop();
            }
        }
        if(finalState.size()>1)
        {
            reverse(finalState.begin(),finalState.end());
        }
        return finalState;
    }
};