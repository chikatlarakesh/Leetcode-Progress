class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> s;
        int maxLen=0;
        for(int i=0;i<n;i++) s.insert(nums[i]);

        for(auto it: s)
        {
            if(s.find(it-1)==s.end())
            {
                int x=it;
                int len=0;
                while(s.find(x)!=s.end())
                {
                    len++;
                    x++;
                }
                maxLen=max(maxLen,len);
            }
        }
        return maxLen;


        // if(n==0) return 0;
        // sort(nums.begin(),nums.end());
        // int count=1,maxLen=1;
        // for(int i=1;i<n;i++)
        // {
        //     if(nums[i]-nums[i-1]==0) continue;
        //     if(nums[i]-nums[i-1]==1) count++;
        //     else count=1;
        //     maxLen=max(maxLen,count);
        // }
        // return maxLen;
    }
};