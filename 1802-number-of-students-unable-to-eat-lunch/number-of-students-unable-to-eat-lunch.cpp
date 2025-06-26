class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        for(int num:students) q.push(num);
        int j=0;
        bool flag=false;
        while(!q.empty())
        {
            flag=false;
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                if(q.front()!=sandwiches[j])
                {
                    int val=q.front();
                    q.pop();
                    q.push(val);
                }
                else
                {
                    flag=true;
                    q.pop();
                    j++;
                    break;
                }
            }
            if(!flag) break;
        }
        return q.size();
    }
};