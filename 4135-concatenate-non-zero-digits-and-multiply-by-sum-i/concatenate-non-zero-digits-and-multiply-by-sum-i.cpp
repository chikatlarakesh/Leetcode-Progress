class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n == 0) return 0;
        string s = to_string(n);
        string num = "";
        int sum = 0;
        for(char ch : s) {
            if(ch != '0') num += ch;
            sum += (ch - '0');
        }
        int x = stoi(num);
        return (long long) x * sum;
    }
};