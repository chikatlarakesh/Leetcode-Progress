class Solution {
    public int totalFruit(int[] fruits) {
        int n = fruits.length;
        if(n == 1) return 1;

        int basket1 = -1, basket2 = -1;
        int basket1Count = 0, basket2Count = 0;
        int l = 0, maxFruits = 0;

        for(int r=0;r<n;r++) {
            if(basket1 == -1) {
                basket1 = fruits[r];
                basket1Count++;
            }
            else if(basket2 == -1 && fruits[r] != basket1) {
                basket2 = fruits[r];
                basket2Count++;
            }
            else if(basket1 == fruits[r]) basket1Count++;
            else if(basket2 == fruits[r]) basket2Count++;
            else {
                while(basket1Count != 0 && basket2Count != 0) {
                    if(basket1 == fruits[l]) basket1Count--;
                    else basket2Count--;
                    l++;
                }
                if(basket1Count == 0) {
                    basket1 = fruits[r];
                    basket1Count++;
                }
                else {
                    basket2 = fruits[r];
                    basket2Count++;
                }
            }
            maxFruits = Math.max(maxFruits,basket1Count + basket2Count);
        }
        return maxFruits;
    }
}