class Solution {
public:
    int binarySearch(int low, int high,int target,vector<int>& nums) {
        int k = -1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(nums[mid] < target) {
                k = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return k;
    }

    int triangleNumber(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        if(n < 3) return 0;
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++) {
            if(nums[i] == 0) continue;
            for(int j=i+1;j<n;j++) {
                if(nums[j] == 0) continue;

                int sum = nums[i] + nums[j];
                int ind = binarySearch(j+1,n-1,sum,nums);
                if(ind != -1) count += ind - j;
            }
        }
        return count;
    }
};