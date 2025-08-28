class Solution {
public:
    void findFirstOccurence(int low,int high,vector<int>& arr,int target,vector<int>& ans)
    {
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(arr[mid]>=target) high=mid-1;
            else low=mid+1;
        }
        if(low!=arr.size() && arr[low]==target) ans[0]=low;
    }

    void findLastOccurence(int low,int high,vector<int>& arr,int target,vector<int>& ans)
    {
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(arr[mid]<=target) low=mid+1;
            else high=mid-1;
        }
        if(high!=-1 && arr[high]==target) ans[1]=high;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> ans(2,-1);
        findFirstOccurence(0,n-1,nums,target,ans);
        findLastOccurence(0,n-1,nums,target,ans);
        return ans;
    }
};