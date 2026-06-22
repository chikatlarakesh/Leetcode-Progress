class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int n=text.length();
        int i,count=0;
        string check="balloon";
        unordered_map<int,int> map;
        for(i=0;i<n;i++)
        {
            map[text[i]]++;
        }
        i=0;
        while(i<n)
        {
            if(map.find(check.at(i))!=map.end())
            {
                map[check[i]]--;
                if(map[check[i]]==0)
                {
                    map.erase(check[i]);
                }
                if(i==6)
                {
                    count++;
                    i=-1;
                }
            }
            else
            {
                break;
            }
            i++;
        }
        return count;
    }
};