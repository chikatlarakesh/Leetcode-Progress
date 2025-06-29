class Solution {
public:
    const int MOD=1000000007;
    int calculatePower(int num,int power)
    {
        if(power==0) return 1;
        long long half=calculatePower(num,power/2);
        long long ans=(half*half)%MOD;
        if(power%2==1) ans=(ans*num)%MOD;
        return ans;
    }
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int l=0,r=n-1;
        int count=0;
        while(l<=r)
        {
            if(nums[l]+nums[r]<=target)
            {
                int power=r-l;
                count=(count+calculatePower(2,power))%MOD;
                l++;
            }
            else r--;
        }
        return count%MOD;
    }
};