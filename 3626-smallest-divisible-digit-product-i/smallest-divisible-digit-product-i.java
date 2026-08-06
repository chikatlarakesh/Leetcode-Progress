class Solution {
    int getProduct(int n) {
        int product = 1;
        while(n > 0) {
            int rem = n % 10;
            product *= rem;
            n /= 10;
        }
        return product;
    }

    public int smallestNumber(int n, int t) {
        while(true) {
            int product = getProduct(n);
            if(product % t == 0) return n;
            n++;
        }
    }
}