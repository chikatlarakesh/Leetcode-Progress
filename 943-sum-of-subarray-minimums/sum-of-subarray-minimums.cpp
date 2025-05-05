class Solution {
public:
    typedef long long ll;
    vector<int> prevSmallestEqual(vector<int>& arr)
    {
        int n=arr.size();
        stack<int> st;
        vector<int> psee(n);
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && arr[st.top()]>arr[i])
            {
                st.pop();
            }
            if(st.empty()) psee[i]=-1;
            else psee[i]=st.top();
            st.push(i);
        }
        return psee;
    }

    vector<int> nextSmallest(vector<int>& arr)
    {
        int n=arr.size();
        stack<int> st;
        vector<int> nse(n);
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && arr[st.top()]>=arr[i])
            {
                st.pop();
            }
            if(st.empty()) nse[i]=n;
            else nse[i]=st.top();
            st.push(i);
        }
        return nse;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        int sum=0;
        long long mod=(int)(1e9+7);
        vector<int> psee=prevSmallestEqual(arr);
        vector<int> nse=nextSmallest(arr);
        for(int i=0;i<n;i++)
        {
            int left=i-psee[i];
            int right=nse[i]-i;
            sum=(sum+(left*right*1ll*arr[i])%mod)%mod;
        }
        return sum;
    }
};