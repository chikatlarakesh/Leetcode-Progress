int count=0;
        unordered_set<char> j(jewels.begin(),jewels.end());
        for(char stone: stones)
        {
            if(j.find(stone)!=j.end())
            {
                count++;
            }
        }
        return count;
