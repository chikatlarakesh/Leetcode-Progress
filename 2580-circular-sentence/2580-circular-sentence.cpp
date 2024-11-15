class Solution {
public:
    bool isCircularSentence(string sentence) {
        bool ans=true;
        int n=sentence.length();
        int i=0;
        if(sentence.at(i)!=sentence.at(n-1))
        {
            return false;
        }
        for(i=0;i<n;i++)
        {
            if(sentence.at(i)==' ')
            {
                if(sentence.at(i-1)!=sentence.at(i+1))
                {
                    ans=false;
                    break;
                }
            }
        }
        return ans;
    }
};