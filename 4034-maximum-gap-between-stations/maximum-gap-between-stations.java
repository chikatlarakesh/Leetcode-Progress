class Solution {
    public int maximumGap(String skill, String station) {
        int n = station.length();
        int m = skill.length();
        int[] left = new int[n];
        int[] right = new int[n];

        int j = 0;
        for(int i=0;i<m;i++) {
            while(skill.charAt(i) != station.charAt(j)) j++;
            left[i] = j;
            j++;
        }

        j = n-1;
        for(int i=m-1;i>=0;i--) {
            while(skill.charAt(i) != station.charAt(j)) j--;
            right[i] = j;
            j--;
        }

        int result = 0;
        for(int i=0;i<m-1;i++) {
            result = Math.max(result,right[i+1]-left[i]);
        }
        return result;
    }
}