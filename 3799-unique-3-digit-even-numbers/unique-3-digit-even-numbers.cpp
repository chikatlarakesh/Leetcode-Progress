class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        unordered_set<int> s;
        sort(digits.begin(),digits.end());
        do
        {
            int val=digits[0]*100 + digits[1]*10 + digits[2];
            if(digits[0]!=0 && digits[2]%2==0)
            {
                s.insert(val);
            }
        }while(next_permutation(digits.begin(),digits.end()));
        return s.size();
    }
};