class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length())
        {
            return false;
        }
        int n=s.length();
        string p=s;
        int i;
        for(i=0;i<n;i++)
        {
            char temp=s.at(0);
            s.erase(0,1);
            s=s+temp;
            if(s==goal)
            {
                return true;
            }
            if(s==p)
            {
                break;
            }
        }
        return false;
    }
};