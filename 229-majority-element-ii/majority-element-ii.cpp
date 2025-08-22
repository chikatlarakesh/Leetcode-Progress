class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int ele1=0,cnt1=0,ele2=0,cnt2=0;

        for(int i=0;i<n;i++)
        {
            if(cnt1==0 && nums[i]!=ele2)
            {
                ele1=nums[i];
                cnt1++;
            }
            else if(cnt2==0 && nums[i]!=ele1)
            {
                ele2=nums[i];
                cnt2++;
            }
            else if(nums[i]==ele1) cnt1++;
            else if(nums[i]==ele2) cnt2++;
            else
            {
                cnt1--;
                cnt2--;
            }
        }

        vector<int> result;
        cnt1=0,cnt2=0;
        int freq=n/3;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==ele1) cnt1++;
            else if(nums[i]==ele2) cnt2++;
        }

        if(cnt1>freq) result.push_back(ele1);
        if(cnt2>freq) result.push_back(ele2);
        sort(result.begin(),result.end());
        return result;
    }
};