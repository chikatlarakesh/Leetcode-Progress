class Solution {
public:
    int countTriples(int n) {
        vector<int> squares((n*n)+1,0);
        for(int i=1;i<=n;i++) {
            int val = i * i;
            squares[val] = 1;
        }

        int count = 0;
        for(int i=1;i<=n;i++) {
            for(int j=i+1;j<=n;j++) {
                int val = (i*i) + (j*j);
                if(val > (n * n)) continue;
                if(squares[val]) count += 2;
            }
        }
        return count;
    }
};