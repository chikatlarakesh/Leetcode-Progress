class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.length();
        vector<int> hash(26,0);
        for(char ch: s) hash[ch - 'a']++;

        string result = "";
        for(int k=0;k<n;k++) {
            char ch = target[k];
            int ind = ch - 'a';

            // find if there is a same character
            if(hash[ind] > 0) {
                result += ch;
                hash[ind]--;
                continue;
            }

            // find if there is a greater character (as there was no same character) 
            for(int i=ind+1;i<26;i++) {
                if(hash[i] > 0) {
                    result += i + 'a';
                    hash[i]--;

                    for(int j=0;j<26;j++) {
                        result.append(hash[j],j+'a');
                    }
                    return result;
                }
            }

            // could not find greater or equal character, so try going back and finding something greater
            while(result.length() > 0) {
                char lastChar = result.back();
                result.pop_back();
                int lastInd = lastChar - 'a';
                hash[lastInd]++;

                for(int i=lastInd+1;i<26;i++) {
                    if(hash[i] > 0) {
                        result += i + 'a';
                        hash[i]--;

                        for(int j=0;j<26;j++) {
                            result.append(hash[j],j+'a');
                        }
                        return result;
                    }
                }
            }
            return "";
        }
        cout<< result<<endl;

        // if resultant string is equal to the target string, try find a lexographically greater string than target by backtracking. If found, modify and return that string. Else return empty string.
        while(result.length() > 0) {
            char lastChar = result.back();
            result.pop_back();
            int lastInd = lastChar - 'a';
            hash[lastInd]++;

            for(int i=lastInd+1;i<26;i++) {
                if(hash[i] > 0) {
                    result += i + 'a';
                    hash[i]--;

                    for(int j=0;j<26;j++) {
                        result.append(hash[j],j+'a');
                    }
                    return result;
                }
            }
        }
        return "";
    }
};