class Solution {
public:
    int helper(string s)
    {
        int sum=0;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            int val=s[i]-'0';
            sum+=val;
        }
        return sum;
    }

    int smallestIndex(vector<int>& nums) {
        int n=nums.size();
        int i;
        for(i=0;i<n;i++)
        {
            if(nums[i]<10 && nums[i]==i) return i;
            else
            {
                string number=to_string(nums[i]);
                int val=helper(number);
                if(val==i) return i;
            }
        }
        return -1;
    }
};