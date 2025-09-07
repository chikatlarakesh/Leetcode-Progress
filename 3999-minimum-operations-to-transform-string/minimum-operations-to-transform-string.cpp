class Solution {
public:
    int minOperations(string s) {
        int operations=0;
        for(char ch:s)
        {
            if(ch=='a') continue;
            operations=max(operations,'z'-ch+1);
        }
        return operations;
    }
};