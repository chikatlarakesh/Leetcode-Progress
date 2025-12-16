class Solution {
public:
    bool isPrime(int n) {
        using ll = long long;
        if(n <= 1) return false;
        if(n <= 3) return true;
        if(n % 2 == 0 || n % 3 == 0) return false;
        for(ll i = 5; i * i <= n; i+=6) {
            if(n % i == 0 || n % (i+2) == 0) return false;
        }
        return true;
    }
    
    bool completePrime(int num) {
        string s = to_string(num);
        int n = s.length();
        int prefix = 0, suffix = 0, b = 1;
        for(int i=0;i<n;i++) {
            prefix = (prefix * 10) + (s[i] - '0');
            suffix += (s[n-i-1] - '0') * b;
            b *= 10;
            if(!isPrime(prefix) || !isPrime(suffix)) return false;
        }
        return true;
    }
};