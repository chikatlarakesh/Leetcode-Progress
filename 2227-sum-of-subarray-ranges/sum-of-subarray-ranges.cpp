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

    long long sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        ll sum=0;
        vector<int> psee=prevSmallestEqual(arr);
        vector<int> nse=nextSmallest(arr);
        for(int i=0;i<n;i++)
        {
            int left=i-psee[i];
            int right=nse[i]-i;
            sum+=left*right*1ll*arr[i];
        }
        return sum;
    }

    vector<int> prevLargestEqual(vector<int>& arr)
    {
        int n=arr.size();
        stack<int> st;
        vector<int> plee(n);
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && arr[st.top()]<arr[i])
            {
                st.pop();
            }
            if(st.empty()) plee[i]=-1;
            else plee[i]=st.top();
            st.push(i);
        }
        return plee;
    }

    vector<int> nextLargest(vector<int>& arr)
    {
        int n=arr.size();
        stack<int> st;
        vector<int> nle(n);
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && arr[st.top()]<=arr[i])
            {
                st.pop();
            }
            if(st.empty()) nle[i]=n;
            else nle[i]=st.top();
            st.push(i);
        }
        return nle;
    }

    long long sumSubarrayMaxs(vector<int>& arr) {
        int n=arr.size();
        ll sum=0;
        vector<int> plee=prevLargestEqual(arr);
        vector<int> nle=nextLargest(arr);
        for(int i=0;i<n;i++)
        {
            int left=i-plee[i];
            int right=nle[i]-i;
            sum+=left*right*1ll*arr[i];
        }
        return sum;
    }

    long long subArrayRanges(vector<int>& arr) {
        long long largest=sumSubarrayMaxs(arr);
        long long smallest=sumSubarrayMins(arr);
        return largest-smallest;
    }
};