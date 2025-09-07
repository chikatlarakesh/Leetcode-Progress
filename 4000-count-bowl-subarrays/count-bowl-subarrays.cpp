class Solution {
public:
    void previousGreater(vector<int>& nums,vector<int>& arr)
    {
        int n=nums.size();
        stack<int> st;
        st.push(0);
        for(int i=1;i<n;i++)
        {
            while(!st.empty() && nums[st.top()]<nums[i]) st.pop();
            if(!st.empty()) arr[i]=st.top();
            st.push(i);
        }
    }

    void nextGreater(vector<int>& nums,vector<int>& arr)
    {
        int n=nums.size();
        stack<int> st;
        st.push(n-1);
        for(int i=n-2;i>=0;i--)
        {
            while(!st.empty() && nums[st.top()]<nums[i]) st.pop();
            if(!st.empty()) arr[i]=st.top();
            st.push(i);
        }
    }

    long long bowlSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<int> pge(n,-1), nge(n,-1);
        previousGreater(nums,pge);
        nextGreater(nums,nge);

        long long ans=0;
        for(int i=0;i<n;i++)
        {
            if(nge[i]!=-1 && (nge[i]-i)+1 >= 3) ans++;
            if(pge[i]!=-1 && (i-pge[i])+1 >= 3) ans++;
        }
        return ans;
    }



















    // long long bowlSubarrays(vector<int>& nums) {
    //     int n=nums.size();
    //     vector<int> pge(n,-1),nge(n,-1);
    //     stack<int> st;

    //     for(int i=0;i<n;i++)
    //         {
    //             while(!st.empty() && nums[st.top()]<=nums[i]) st.pop();
    //             if(!st.empty()) pge[i]=st.top();
    //             st.push(i);
    //         }

    //     while(!st.empty()) st.pop();
    //     for(int i=n-1;i>=0;i--)
    //         {
    //             while(!st.empty() && nums[st.top()]<=nums[i]) st.pop();
    //             if(!st.empty()) nge[i]=st.top();
    //             st.push(i);
    //         }

    //     long long result=0;
    //     for(int i=0;i<n;i++)
    //         {
    //             if(pge[i]!=-1 && nge[i]!=-1)
    //             {
    //                 if(nge[i]-pge[i]>=2) result++;
    //             }
    //         }
    //     return result;
    // }
};