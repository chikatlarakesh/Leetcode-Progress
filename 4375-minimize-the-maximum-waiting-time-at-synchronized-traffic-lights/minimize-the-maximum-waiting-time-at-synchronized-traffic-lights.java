class Solution {
    public int minPenalty(int period, int[] lights, int[] arrivalTime) {
        int maxDuration = 0;
        for(int light: lights) {
            maxDuration = Math.max(maxDuration,light);
        }

        int penalty = 0;
        int n = arrivalTime.length;
        for(int i=0;i<n;i++) {
            int r = arrivalTime[i] % period;
            if(r >= maxDuration) {
                penalty = Math.max(penalty,period - r);
            }
        }
        return penalty;
    }
}