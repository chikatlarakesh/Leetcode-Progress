class Solution {
    boolean isPossible(int maxCapacity,int[] weights,int days) {
        int count = 0,currCapacity = 0;
        for(int weight : weights) {
            if(weight > maxCapacity) return false;

            currCapacity += weight;
            if(currCapacity > maxCapacity) {
                count++;
                currCapacity = weight;
            }
        }
        count++;
        return count <= days;
    }

    public int shipWithinDays(int[] weights, int days) {
        int n = weights.length;

        int low = 1, high = Integer.MAX_VALUE;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(isPossible(mid,weights,days)) {
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return low;
    }
}