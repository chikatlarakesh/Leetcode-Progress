class Solution {
    class Pair {
        int first;
        int second;

        public Pair(int first,int second) {
            this.first = first;
            this.second = second;
        }
    }

    public int[] arrayRankTransform(int[] arr) {
        int n = arr.length;
        PriorityQueue<Pair> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a.first));

        for(int i=0;i<n;i++) {
            pq.offer(new Pair(arr[i],i));
        }

        int rank = 0, prev = Integer.MAX_VALUE;
        int[] result = new int[n];
        while(!pq.isEmpty()) {
            int index = pq.peek().second;
            pq.poll();
            if(arr[index] != prev) rank++;
            result[index] = rank;
            prev = arr[index];
        }
        return result;
    }
}