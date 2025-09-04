class Solution {
public:
    int findClosest(int x, int y, int z) {
        int distance1=abs(x-z);
        int distance2=abs(y-z);
        if(distance1==distance2) return 0;
        else if(distance1<distance2) return 1;
        else return 2;
    }
};