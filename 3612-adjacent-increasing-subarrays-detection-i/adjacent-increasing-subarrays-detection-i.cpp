class Solution {
public:
    bool isPossible(int left,int right,vector<int>& nums,int k) {
        for(int i=left-1;i>=left-k+1;i--) {
            if(nums[i] >= nums[i+1]) return false;
        }

        for(int i=right+1;i<=right+k-1;i++) {
            if(nums[i] <= nums[i-1]) return false;
        }
        return true;
    }

    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        for(int i=k-1;i<=n-k-1;i++) {
            if(isPossible(i,i+1,nums,k)) return true;
        }
        return false;
    }
};