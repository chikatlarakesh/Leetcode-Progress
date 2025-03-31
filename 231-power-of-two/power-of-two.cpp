class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        if((n&n-1)==0) return true;
        return false;
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