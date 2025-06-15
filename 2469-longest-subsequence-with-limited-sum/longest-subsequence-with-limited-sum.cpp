class Solution {
public:
    int maxSize(vector<int>& nums,int limit)
    {
        int count=0,sum=0;
        for(int num:nums)
        {
            if(num+sum<=limit)
            {
                sum+=num;
                count++;
            }
            else break;
        }
        return count;
    }

    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n=nums.size();
        int m=queries.size();
        vector<int> result;
        sort(nums.begin(),nums.end());
        for(int num:queries)
        {
            result.push_back(maxSize(nums,num));
        }
        return result;
    }
};