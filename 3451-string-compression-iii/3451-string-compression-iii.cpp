class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        int n = word.length();
        int count = 1;
        for (int i = 1; i < n; i++) 
        {
            if (word[i] == word[i - 1]) 
            {
                count++;

                if (count == 9) 
                {
                    comp += to_string(count) + word[i - 1];
                    count = 0;
                }
            } 
            else 
            {
                if (count > 0) 
                {
                    comp += to_string(count) + word[i - 1];
                }
                count = 1;
            }
        }
        if(count>0)
        {
            comp += to_string(count) + word[n - 1];
        }
        return comp;
    }
};