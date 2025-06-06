class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        int l=0,basket1=-1,basket2=-1,cnt1=0,cnt2=0,maxFruits=0;
        for(int r=0;r<n;r++)
        {
            if(basket1==-1)
            {
                basket1=fruits[r];
                cnt1++;
            }
            else if(basket2==-1 && fruits[r]!=basket1)
            {
                basket2=fruits[r];
                cnt2++;
            }
            else if(fruits[r]==basket1) cnt1++;
            else if(fruits[r]==basket2) cnt2++;
            else
            {
                while(cnt1!=0 && cnt2!=0)
                {
                    if(fruits[l]==basket1) cnt1--;
                    else cnt2--;
                    l++;
                }
                if(cnt1==0) 
                {
                    basket1=fruits[r];
                    cnt1++;
                }
                else
                {
                    basket2=fruits[r];
                    cnt2++;
                }
            }
            maxFruits=max(maxFruits,(cnt1+cnt2));
        }
        return maxFruits;
    }
};