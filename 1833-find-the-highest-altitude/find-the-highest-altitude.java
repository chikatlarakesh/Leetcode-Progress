class Solution {
    public int largestAltitude(int[] gain) {
        int currAltitude = 0, highestAltitude = 0;
        for(int alt : gain) {
            currAltitude += alt;
            highestAltitude = Math.max(highestAltitude,currAltitude);
        }
        return highestAltitude;
    }
}