class Solution {
    int countGoodSubarrays(int[] nums,int k) {
        int n = nums.length;
        if(k == 0) return 0;
        Map<Integer,Integer> mp = new HashMap<>();
        int l = 0,count = 0;

        for(int r=0;r<n;r++) {
            mp.put(nums[r],mp.getOrDefault(nums[r],0)+1);

            while(mp.size() > k) {
                mp.put(nums[l],mp.get(nums[l])-1);
                if(mp.get(nums[l]) == 0) {
                    mp.remove(nums[l]);
                }
                l++;
            }

            count += r - l + 1;
        }
        return count;
    }

    public int subarraysWithKDistinct(int[] nums, int k) {
        return countGoodSubarrays(nums,k) - countGoodSubarrays(nums,k-1);
    }
}