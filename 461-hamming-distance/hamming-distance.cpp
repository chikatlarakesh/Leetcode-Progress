class Solution {
public:
    int hammingDistance(int x, int y) {
        int result=x^y;
        int count=0;
        while(result)
        {
            result=(result&result-1);
            count++;
        }
        return count;
    }
};