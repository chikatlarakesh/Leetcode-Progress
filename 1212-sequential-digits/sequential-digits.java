class Solution {
    public List<Integer> sequentialDigits(int low, int high) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();

        for(int i=1;i<9;i++) {
            pq.offer(i);
        }

        List<Integer> result = new ArrayList<>();
        while(!pq.isEmpty()) {
            int value = pq.poll();
            if(value > high) break;
            if(value >= low && value <= high) {
                result.add(value);
            }

            int lastDigit = value % 10;
            if(lastDigit == 9) continue;
            int newValue = (value * 10) + (lastDigit + 1);
            pq.offer(newValue);
        }
        return result;
    }
}