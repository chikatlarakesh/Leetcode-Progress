class Solution {
public:
    int GCD(int a,int b)
    {
        int c=a%b;
        if(c==0) return b;
        else return GCD(b,c);
    }
    int findGCD(vector<int>& nums) {
        int maxVal=*max_element(nums.begin(),nums.end());
        int minVal=*min_element(nums.begin(),nums.end());
        return GCD(maxVal,minVal);
    }
};