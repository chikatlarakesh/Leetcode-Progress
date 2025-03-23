class Solution {
public:
    int maxContainers(int n, int w, int maxWeight) {
        n=n*n;
        int res=maxWeight/w;
        return min(res,n);
    }
};