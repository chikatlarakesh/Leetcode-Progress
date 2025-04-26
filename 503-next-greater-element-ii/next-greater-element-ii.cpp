class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        stack<int> st;
        vector<int> result;
        int i;
        for(i=2*n-1;i>=0;i--)
        {
            int j=i%n;
            if(!st.empty() && nums[j]>=st.top())
            {
                while(!st.empty() && st.top()<=nums[j])
                {
                    st.pop();
                }
            }
            if(i<n && !st.empty())
            {
                result.push_back(st.top());
            }
            else if(i<n && st.empty())
            {
                result.push_back(-1);
            }
            st.push(nums[j]);
        }
        reverse(result.begin(),result.end());
    return result;





        // int n=nums.size();
        // int i,j;
        // vector<int> result;
        // for(i=0;i<n;i++)
        // {
        //     for(j=i+1;j<=i+n-1;j++)
        //     {
        //         int index=j%n;
        //         if(nums[index]>nums[i])
        //         {
        //             result.push_back(nums[index]);
        //             break;
        //         }
        //     }
        //     if(result.size()==i)
        //     {
        //         result.push_back(-1);
        //     }
        // }
        // return result;
    }
};