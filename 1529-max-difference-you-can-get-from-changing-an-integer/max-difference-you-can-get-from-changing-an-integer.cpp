class Solution {
public:
    int maxDiff(int num) {
        string number=to_string(num);
        int n=number.length();
        char largest=number[0],smallest=number[0];
        int smallIndex=0;
        string maximum="",minimum="";
        if(number[0]=='9')
        {
            for(char ch:number)
            {
                if(ch!='9')
                {
                    largest=ch;
                    break;
                }
            }
        }
        if(number[0]=='1')
        {
            for(int i=0;i<n;i++)
            {
                if(number[i]!='1' && number[i]!='0')
                {
                    smallIndex=i;
                    smallest=number[i];
                    break;
                }
            }
        }
        if(largest!='9')
        {
            for(int i=0;i<n;i++)
            {
                if(number[i]==largest)
                {
                    maximum+='9';
                }
                else maximum+=number[i];
            }
        }
        else maximum=number;
        if(smallIndex==0)
        {
            for(int i=0;i<n;i++)
            {
                if(number[i]==smallest)
                {
                    minimum+='1';
                }
                else minimum+=number[i];
            }
        }
        else
        {
            for(int i=0;i<n;i++)
            {
                if(number[i]==smallest)
                {
                    minimum+='0';
                }
                else minimum+=number[i];
            }
        }
        int maxi=stoi(maximum);
        int mini=stoi(minimum);
        return maxi-mini;
    }
};