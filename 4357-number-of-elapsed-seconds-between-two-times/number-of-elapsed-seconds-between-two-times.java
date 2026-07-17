class Solution {
    public int secondsBetweenTimes(String startTime, String endTime) {
        int n = startTime.length();

        int totalSecs = 3600;
        int startTotalSecs = 0, endTotalSecs = 0;
        for(int i=0;i<n;i+=3) {
            int start = Integer.valueOf(startTime.substring(i,i+2));
            int end = Integer.valueOf(endTime.substring(i,i+2));
            startTotalSecs += (start * totalSecs);
            endTotalSecs += (end * totalSecs);
            totalSecs /= 60;
        }
        return endTotalSecs - startTotalSecs;
    }
}