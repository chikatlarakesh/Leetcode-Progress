class MinStack {
public:
    stack<long long> st;
    long long min=INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty())
        {
            st.push(val);
            min=val;
        }
        else
        {
            if(val<min)
            {
                long long x=2*(long long)val-min;
                st.push(x);
                min=val;
            }
            else st.push(val);
        }
    }
    
    void pop() {
        if(st.top()<min)
        {
            min=2*min-st.top();
        }
        st.pop();
    }
    
    int top() {
        if(st.top()<min)
        {
            return min;
        }
        return st.top();
    }
    
    int getMin() {
        return min;
    }

    //stack<pair<int,int>> st;
    // MinStack() {
        
    // }
    
    // void push(int val) {
    //     if(st.empty())
    //     {
    //         st.push({val,val});
    //     }
    //     else 
    //     {
    //         st.push({val,min(val,st.top().second)});
    //     }
    // }
    
    // void pop() {
    //     st.pop();
    // }
    
    // int top() {
    //     return st.top().first;
    // }
    
    // int getMin() {
    //     return st.top().second;
    // }

    // // stack<int> s;
    // // MinStack() {
        
    // // }
    
    // // void push(int val) {
    // //     s.push(val);
    // // }
    
    // // void pop() {
    // //     s.pop();
    // // }
    
    // // int top() {
    // //     return s.top();
    // // }
    
    // // int getMin() {
    // //     int min=INT_MAX;
    // //     stack<int> s1;
    // //     while(!s.empty())
    // //     {
    // //         if(s.top()<min)
    // //         {
    // //             min=s.top();
    // //         }
    // //         s1.push(s.top());
    // //         s.pop();
    // //     }
    // //     while(!s1.empty())
    // //     {
    // //         s.push(s1.top());
    // //         s1.pop();
    // //     }
    // //     return min;
    // // }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */