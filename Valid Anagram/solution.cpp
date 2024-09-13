class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
        return false;
    }
    string sorted_s = s;
    string sorted_t = t;
    sort(sorted_s.begin(), sorted_s.end());
    sort(sorted_t.begin(), sorted_t.end());

    return sorted_s == sorted_t;
} 

};
