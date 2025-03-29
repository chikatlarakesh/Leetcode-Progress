class Solution {
public:
    string convertToBinary(string date){
        string binary="";
        int val=stoi(date);
        while(val>1)
        {
            binary+=(val%2)+'0';
            val=val/2;
        }
        binary+=val+'0';
        reverse(binary.begin(),binary.end());
        return binary;
    }

    string convertDateToBinary(string date) {
        string result="",convertDate="";
        int n=date.length();
        for(int i=0;i<n;i++)
        {
            if(date[i]=='-')
            {
                result+=convertToBinary(convertDate);
                result+='-';
                convertDate="";
            }
            else convertDate+=date[i];
        }
        result+=convertToBinary(convertDate);
        return result;
    }
};