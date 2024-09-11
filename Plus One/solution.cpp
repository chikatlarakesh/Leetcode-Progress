vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        int i=0;
        for(i=n-1;i>=0;i--)
        {
            if(digits[i]<9)
            {
                digits[i]=digits[i]+1;
                return digits;
            }
            digits[i]=0;
        }
        digits.insert(digits.begin(),1);
        return digits;
    }
