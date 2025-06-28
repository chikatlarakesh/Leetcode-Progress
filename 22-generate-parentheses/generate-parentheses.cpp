class Solution {
public:
    void generateParenthesis(int length,int count,int n,string s,vector<string>& result)
    {
        if(length==n)
        {
            if(count==0) result.push_back(s);
            return;
        }
        generateParenthesis(length+1,count+1,n,s+'(',result);
        if(count>0) generateParenthesis(length+1,count-1,n,s+')',result);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generateParenthesis(1,1,n*2,"(",result);
        return result;
    }
};