class Solution {
public:
    bool isSameAfterReversals(int num) {
        // int i;
        // int val=num;
        // for(i=0;i<2;i++)
        // {
        //     string s=to_string(val);
        //     reverse(s.begin(),s.end());
        //     int val=stoi(s);
        // }
        // if(val==num)
        // {
        //     return true;
        // }
        // return false;
        if(num==0)
        {
            return true;
        }
        if(num%10==0)
        {
            return false;
        }
        return true;
    }
};