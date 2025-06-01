class Solution {
public:
    int distMoney(int money, int children) {
        if(children>money) return -1;
        int remMoney=money-children;
        int maxAllot=remMoney/7;
        int leftOver=remMoney%7;
        if(maxAllot>children) 
        {
            return children-1;
        }
        else if(maxAllot<children)
        {
            int remChild=children-maxAllot;
            if(leftOver==3 && remChild==1) return max(0,maxAllot-1);
            else return maxAllot;
        }
        else
        {
            if(leftOver==0) return maxAllot;
            else return maxAllot-1;
        }
        return 0;
    }
};