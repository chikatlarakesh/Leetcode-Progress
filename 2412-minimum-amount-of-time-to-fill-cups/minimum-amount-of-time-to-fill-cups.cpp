class Solution {
public:
    int fillCups(vector<int>& amount) {
        int minSeconds=0,sum=0,maxi=0;
        for(int num:amount)
        {
            maxi=max(maxi,num);
            sum+=num;
        }
        int val=sum/2;
        if(sum%2==1) val++;
        minSeconds=max(maxi,val);
        return minSeconds;
    }
};