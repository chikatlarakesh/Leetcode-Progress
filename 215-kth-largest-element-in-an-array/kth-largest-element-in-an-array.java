class Solution {
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        int n = nums.length;

        for(int i=0;i<n;i++) {
            if(pq.size() == k && nums[i] > pq.peek()) {
                pq.poll();
            }
            if(pq.size() < k) pq.offer(nums[i]);
        }
        return pq.peek();
    }
}