class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int i,largestArea=0,nse,pse,element;
        stack<int> st;
        for(i=0;i<n;i++)
        {
            while(!st.empty() && heights[st.top()]>heights[i])
            {
                nse=i;
                element=st.top();
                st.pop();
                if(st.empty()) pse=-1;
                else pse=st.top();
                largestArea=max(largestArea,(heights[element]*(nse-pse-1)));
            }
            st.push(i);
        }

        while(!st.empty())
        {
            nse=n;
            element=st.top();
            st.pop();
            if(st.empty()) pse=-1;
            else pse=st.top();
            largestArea=max(largestArea,(heights[element]*(nse-pse-1)));
        }
        return largestArea;
    }

    // vector<int> prevSmallestEqual(vector<int>& arr)
    // {
    //     int n=arr.size();
    //     stack<int> st;
    //     vector<int> psee(n);
    //     for(int i=0;i<n;i++)
    //     {
    //         while(!st.empty() && arr[st.top()]>arr[i])
    //         {
    //             st.pop();
    //         }
    //         if(st.empty()) psee[i]=-1;
    //         else psee[i]=st.top();
    //         st.push(i);
    //     }
    //     return psee;
    // }

    // vector<int> nextSmallest(vector<int>& arr)
    // {
    //     int n=arr.size();
    //     stack<int> st;
    //     vector<int> nse(n);
    //     for(int i=n-1;i>=0;i--)
    //     {
    //         while(!st.empty() && arr[st.top()]>=arr[i])
    //         {
    //             st.pop();
    //         }
    //         if(st.empty()) nse[i]=n;
    //         else nse[i]=st.top();
    //         st.push(i);
    //     }
    //     return nse;
    // }

    // int largestRectangleArea(vector<int>& heights) {
    //     int n=heights.size();
    //     vector<int> psee=prevSmallestEqual(heights);
    //     vector<int> nse=nextSmallest(heights);
    //     int largestArea=0,sum=0;
    //     for(int i=0;i<n;i++)
    //     {
    //         int width=nse[i]-psee[i]-1;
    //         sum=heights[i]*width;
    //         largestArea=max(largestArea,sum);
    //     }
    //     return largestArea;
    // }
};