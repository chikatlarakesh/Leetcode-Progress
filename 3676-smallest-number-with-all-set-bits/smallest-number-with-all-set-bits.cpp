class Solution {
public:
    int smallestNumber(int n) {
        int power = 2;
        while(true) {
            int val = power - 1;
            if(val >= n) return val;
            power = power << 1;
        }
        return 0;
    }
};