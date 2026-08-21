class Solution {
    public int subarraySum(int[] arr, int k) {
        int n = arr.length;
        int prefix = 0;
        
        Map<Integer,Integer> mp = new HashMap<>();
        mp.put(0,1);
        int count = 0;
        
        for(int i=0;i<n;i++) {
            prefix += arr[i];
            if(mp.containsKey(prefix - k)) {
                int j = mp.get(prefix - k);
                count+= mp.get(prefix - k);
            }
            mp.put(prefix,mp.getOrDefault(prefix,0)+1);
        }
        return count;
    }
}