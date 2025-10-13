class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();
        vector<string> result;

        for(int i=0;i<n;i++) {
            if(result.empty()) {
                result.push_back(words[i]);
            }
            else {
                string s = words[i];
                string last = result.back();
                sort(s.begin(),s.end());
                sort(last.begin(),last.end());
                if(last != s) {
                    result.push_back(words[i]);
                }
            }
        }
        return result;
    }
};