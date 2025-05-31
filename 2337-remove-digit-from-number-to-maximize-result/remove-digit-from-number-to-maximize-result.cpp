class Solution {
public:
    string removeDigit(string number, char digit) {
        int n=number.length();
        int i=0;
        while(i<n)
        {
            if(number[i]==digit && number[i+1]>digit)
            {
                number.erase(i,1);
                return number;
            }
            i++;
        }
        i=n-1;
        while(i>=0)
        {
            if(number[i]==digit)
            {
                number.erase(i,1);
                break;
            }
            i--;
        }
        return number;
    }
};