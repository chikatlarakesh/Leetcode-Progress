class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();
        vector<unordered_set<int>> langMap(m + 1);
        for (int i = 0; i < m; i++) {
            for (int lang : languages[i]) {
                langMap[i + 1].insert(lang);
            }
        }

        unordered_set<int> needTeach;
        for (auto& f : friendships) {
            bool talk = false;
            for (int l : langMap[f[0]]) {
                if (langMap[f[1]].count(l)) {
                    talk = true;
                    break;
                }
            }
            if (!talk) {
                needTeach.insert(f[0]);
                needTeach.insert(f[1]);
            }
        }

        vector<int> freq(n + 1, 0);
        int popularLang = 0;
        for (int person : needTeach) {
            for (int lang : langMap[person]) {
                freq[lang]++;
                popularLang = max(popularLang, freq[lang]);
            }
        }
        return (int)needTeach.size() - popularLang;
    }
};