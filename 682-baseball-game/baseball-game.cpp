class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        int n=operations.size();
        int i;
        for(i=0;i<n;i++)
        {
            if(operations[i]=="C")
            {
                st.pop();
            }
            else if(operations[i]=="D")
            {
                int val=st.top()*2;
                st.push(val);
            }
            else if(operations[i]=="+")
            {
                int top=st.top();
                st.pop();
                int sum=st.top()+top;
                st.push(top);
                st.push(sum);
            }
            else
            {
                int val=stoi(operations[i]);
                st.push(val);
            }
        }
        int sum=0;
        while(!st.empty())
        {
            sum+=st.top();
            st.pop();
        }
        return sum;
    }
};