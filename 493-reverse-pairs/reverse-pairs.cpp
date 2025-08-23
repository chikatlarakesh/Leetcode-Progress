class Solution {
public:
    void merge(int low,int mid,int high,vector<int>& nums,vector<int>& ans)
  {
    int left=low;
    int right=mid+1;

    vector<int> temp;
    while(left<=mid && right<=high)
    {
      if(nums[left]<=nums[right])
      {
        temp.push_back(nums[left]);
        left++;
      }
      else
      {
        temp.push_back(nums[right]);
        right++;
      }
    }

    while(left<=mid)
    {
      temp.push_back(nums[left]);
      left++;
    }

    while(right<=high)
    {
      temp.push_back(nums[right]);
      right++;
    }

    for(int i=low;i<=high;i++)
    {
      nums[i]=temp[i-low];
    }
  }

  void countPairs(int low,int mid,int high,vector<int>& nums,vector<int>& ans)
  {
    int right=mid+1;
    for(int i=low;i<=mid;i++)
    {
        while(right<=high && ((long long)nums[i]>2LL*nums[right])) right++;
        ans[0]+=right-(mid+1);
    }
  }

    void mergeSortHelper(int low,int high,vector<int>& nums,vector<int>& ans)
    {
      if(low>=high) return;
      int mid=low+(high-low)/2;
      mergeSortHelper(low,mid,nums,ans);
      mergeSortHelper(mid+1,high,nums,ans);
      countPairs(low,mid,high,nums,ans);
      merge(low,mid,high,nums,ans);
    }

    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(1,0);
        mergeSortHelper(0,n-1,nums,ans);
        return ans[0];
    }
};