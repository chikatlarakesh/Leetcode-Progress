class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int maxBottles = numBottles,remBottles = 0;
        while(numBottles >= numExchange) {
            remBottles = numBottles % numExchange;
            numBottles /= numExchange;
            maxBottles += numBottles;
            numBottles += remBottles;
        }
        return maxBottles;
    }
};