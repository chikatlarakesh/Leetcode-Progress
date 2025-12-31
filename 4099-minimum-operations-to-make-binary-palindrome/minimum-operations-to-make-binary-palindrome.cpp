class Solution {
public:
    bool isBPalindrome(int num) {
        string s;
        while(num > 0) {
            s.push_back(char((num%2) + '0'));
            num /= 2;
        }

        int n = s.length();
        int i = 0, j = n-1;
        while(i < j) {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
        
    }
    
    vector<int> minOperations(vector<int>& nums) {
        int maxi = *max_element(nums.begin(),nums.end());
        vector<int> temp(10000+1,1e9);

        for(int i=1;i<=10000;i++) {
            if(isBPalindrome(i)) temp[i] = 0;
        }

        for(int i=1;i<=10000;i++) {
            if(temp[i-1]+1 < temp[i]) temp[i] = temp[i-1] + 1;
        }

        for(int i=10000-1;i>=1;i--) {
            if(temp[i+1]+1 < temp[i]) temp[i] = temp[i+1] + 1;
        }

        vector<int> result;
        for(int num: nums) result.push_back(temp[num]);
        return result;
    }
};