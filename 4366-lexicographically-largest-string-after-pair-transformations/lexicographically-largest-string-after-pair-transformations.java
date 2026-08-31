class Solution {
    public String[] largestString(int[] nums) {
        int n = nums.length;

        String[] result = new String[n];

        for(int i=0;i<n;i++) {
            int count = nums[i];
            char ch = 'a';
            StringBuilder sb = new StringBuilder();

            while(count > 0 && ch < 'z') {
                if(count % 2 == 1) {
                    sb.append(ch);
                }
                count /= 2;
                ch++;
            }

            while(count > 0) {
                sb.append(ch);
                count--;
            }

            result[i] = sb.reverse().toString();
        }
        return result;
    }
}