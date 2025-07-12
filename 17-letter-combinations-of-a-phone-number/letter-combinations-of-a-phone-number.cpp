class Solution {
public:
    void possibleCombinations(int i,string& digits,string& s,unordered_map<char,string>& mp,vector<string>& result)
    {
        if(s.length()==digits.length())
        {
            result.push_back(s);
            return;
        }
        string numComb=mp[digits[i]];
        for(int j=0;j<numComb.length();j++)
        {
            s+=numComb[j];
            possibleCombinations(i+1,digits,s,mp,result);
            s.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> mp = {{'2', "abc"},{'3', "def"},{'4', "ghi"},{'5', "jkl"},{'6', "mno"},{'7', "pqrs"},{'8', "tuv"},{'9', "wxyz"}};
        vector<string> result;
        if(digits.empty()) return result;
        string s="";
        possibleCombinations(0,digits,s,mp,result);
        return result;
    }
};