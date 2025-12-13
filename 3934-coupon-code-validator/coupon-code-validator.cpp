class Solution {
public:
    bool checkSpecial(string s)
    {
        for(char ch:s)
            {
                if(ch!='_' && !isalnum(ch)) return true;
            }
        return false;
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n=code.size();
        vector<pair<int,string>> result;
        unordered_map<string,int> priority={
            {"electronics",0},
            {"grocery",1},
            {"pharmacy",2},
            {"restaurant",3}
        };
        for(int i=0;i<n;i++)
            {
                string s=code[i];
                if(isActive[i]==false) continue;
                else if(priority.find(businessLine[i])==priority.end()) continue;
                else if(s.empty() || checkSpecial(s)==true) continue;
                result.push_back({priority[businessLine[i]],s});
            }

        sort(result.begin(),result.end());

        vector<string> ans;
        for(auto& x: result) ans.push_back(x.second);
        return ans;      
    }
};