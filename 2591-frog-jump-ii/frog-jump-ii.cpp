class Solution {
public:
    int maxJump(vector<int>& stones) {
        int n=stones.size();
        int prevStone=0,maxLen=0;
        for(int i=0;i<n;i+=2)
        {
            maxLen=max(maxLen,stones[i]-prevStone);
            prevStone=stones[i];
        }
        prevStone=0;
        for(int i=1;i<n;i+=2)
        {
            maxLen=max(maxLen,stones[i]-prevStone);
            prevStone=stones[i];
        }
        return maxLen;
    }
};