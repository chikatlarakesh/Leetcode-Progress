class Solution {
public:
    // Try to write it in one go, only run when you're sure that it will work, as there will not be a compiler in the interview. They will just check the code ig.
    int firstoccurence(vector<int>& nums, int target){
        int n=nums.size();
        int left=0;
        int right=n-1;
        int ans=-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]==target){
                ans=mid;
                right=mid-1;
            }
            else if(nums[mid]<target){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return ans;
        
    }
    int lastoccurence(vector<int>& nums, int target){
        int n=nums.size();
        int left=0;
        int right=n-1;
        int ans=-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]==target){
                ans=mid;
                left=mid+1;
            }
            else if(nums[mid]<target){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return ans;
        
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        if(nums.size()==0){
            return {-1,-1}; 
        }
        int first=firstoccurence(nums,target);
        int last=lastoccurence(nums,target);
        res.push_back(first);
        res.push_back(last); 
        return res;
    }
};