class Solution {
    public int minTotalCost(int n) {
        if(n == 1) return 0;
        return (n-1) + minTotalCost(n-1);
    }

    public int minCost(int n) {
        return minTotalCost(n);
    }
}