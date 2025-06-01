class Solution {
public:
    int countAsterisks(string s) {
        int asterisks=0,bars=0;
        for(char ch:s)
        {
            if(ch=='|') bars++;
            if(bars%2==0 && ch=='*') asterisks++;
        }
        return asterisks;
    }
};