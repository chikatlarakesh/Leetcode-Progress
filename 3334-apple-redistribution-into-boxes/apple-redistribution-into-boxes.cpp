class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n = capacity.size();
        int totalApples = accumulate(apple.begin(),apple.end(),0);
        sort(capacity.rbegin(),capacity.rend());

        for(int i=0;i<n;i++) {
            totalApples -= capacity[i];
            if(totalApples <= 0) return i+1;
        }
        return 0;
    }
};