class Solution {
public:
    int totalMoney(int n) {
        int money = 0,count = 0, dayWiseMoney = 0;

        for(int i=1;i<=n;i++) {
            if(i % 7 == 1) {
                count++;
                dayWiseMoney = count;
            }
            else dayWiseMoney++;
            money += dayWiseMoney;
        }
        return money;
    }
};