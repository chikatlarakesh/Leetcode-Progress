class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fiveDollars=0,tenDollars=0,reqChange=0;
        for(int num:bills)
        {
            if(num==20)
            {
                if(tenDollars>=1 && fiveDollars>=1)
                {
                    tenDollars--;
                    fiveDollars--;
                }
                else if(fiveDollars>=3) fiveDollars-=3;
                else return false;
            }
            else if(num==10)
            {
                tenDollars++;
                if(fiveDollars>0)
                {
                    fiveDollars--;
                }
                else return false;
            }
            else fiveDollars++;
        }
        return true;
    }
};