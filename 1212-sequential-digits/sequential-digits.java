class Solution {
    public List<Integer> sequentialDigits(int low, int high) {
        Queue<Integer> q = new LinkedList<>();

        for(int i=1;i<9;i++) {
            q.offer(i);
        }

        List<Integer> result = new ArrayList<>();
        while(!q.isEmpty()) {
            int value = q.poll();
            if(value > high) break;
            if(value >= low && value <= high) {
                result.add(value);
            }

            int lastDigit = value % 10;
            if(lastDigit == 9) continue;
            int newValue = (value * 10) + (lastDigit + 1);
            q.offer(newValue);
        }
        return result;
    }
}