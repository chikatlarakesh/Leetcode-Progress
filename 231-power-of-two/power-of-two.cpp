class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n>0 && (n&n-1)==0);
        // if(n<=1)
        // {
        //     if(n==1)
        //     {
        //         return true;
        //     }
        //     else
        //     {
        //         return false;
        //     }
        // }
        // while(n>1)
        // {
        //     if(n%2!=0)
        //     {
        //         return false;
        //     }
        //     n=n/2;
        // }
        // return true;
    }
};