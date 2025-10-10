class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        using ll = long long;
        int m = skill.size();
        int n = mana.size();
        vector<ll> currTime(m), finishTime(n);
        ll prevTime = 0;

        // 1st potion brew
        for(int j=0;j<m;j++) {
            currTime[j] = (skill[j] * mana[0]) + prevTime;
            prevTime = currTime[j];
        }
        finishTime = currTime;

        // brew all the remaining potions
        for(int i=1;i<n;i++) {
            currTime[0] = finishTime[0] + (mana[i] * skill[0]);
            for(int j=1;j<m;j++) {
                currTime[j] = max(currTime[j-1],finishTime[j]) + (mana[i] * skill[j]);
            }

            finishTime[m-1] = currTime[m-1];
            for(int k=m-1;k>0;k--) {
                finishTime[k-1] = finishTime[k] - (mana[i] * skill[k]);
            }
        }
        return (long long) finishTime[m-1];
    }
};