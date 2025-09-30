class Solution {
public:
    int triangularSum(vector<int>& nums) {
        vector<int> newArr = nums;
        while(newArr.size() > 1) {
            int m = newArr.size();
            vector<int> temp(m-1);
            for(int i=0;i<m-1;i++) {
                temp[i] = (newArr[i] + newArr[i+1]) % 10;
            }
            newArr = temp;
        }
        return newArr[0];
    }
};