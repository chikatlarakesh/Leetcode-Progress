class Solution {
public:
    int numDifferentIntegers(string word) {
        unordered_map<string,int> mp;  
        for(int i=0;i<word.size();i++) 
        {
            if(isdigit(word[i])) 
            {
			    string s;
                while(word[i]=='0') i++;
                while(isdigit(word[i])) s+=word[i++];
                mp[s]++;
            }
        }
        return mp.size();
    }
};