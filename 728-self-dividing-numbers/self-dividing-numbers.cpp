class Solution {
public:
    bool helper(int i)
    {
        int num=i;
        while(num>0)
        {
            int val=num%10;
            if(val==0 || i%val!=0) return false;
            num=num/10;
        }
        return true;
    }

    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;
        for(int i=left;i<=right;i++)
        {
            bool ans=helper(i);
            if(ans) result.push_back(i);
        }
        return result;
    }
};