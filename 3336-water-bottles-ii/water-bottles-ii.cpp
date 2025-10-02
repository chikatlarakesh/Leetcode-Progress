class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int emptyBottles = 0, bottlesDrunk = 0;;
        while(numBottles + emptyBottles >= numExchange) { 
            bottlesDrunk += numBottles;
            emptyBottles += numBottles;
            emptyBottles = emptyBottles - numExchange;
            numBottles = 1;
            numExchange++;
        }
        if(numBottles) bottlesDrunk += numBottles;
        return bottlesDrunk;
    }
};