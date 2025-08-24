class Solution {
public:
    int maxDepth(string s) {
        int count=0,maxDepth=0;
        for(char ch:s)
        {
            if(ch=='(') count++;
            else if(ch==')') count--;
            maxDepth=max(maxDepth,count);
        }
        return maxDepth;
    }
};