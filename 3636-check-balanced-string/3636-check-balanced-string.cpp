class Solution {
public:
    bool isBalanced(string num) {
        int n=num.length();
        int odd=0;
        int even=0;
        int i;
        for(i=0;i<n;i++)
        {
            if(i%2==0)
            {
                even=even+(num.at(i)-'0');
            }
            else
            {
                odd=odd+(num.at(i)-'0');
            }
        }
        if(odd==even)
        {
            return true;
        }
        return false;
    }
};