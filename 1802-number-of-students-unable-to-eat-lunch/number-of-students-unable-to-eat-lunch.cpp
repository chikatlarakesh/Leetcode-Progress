class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int zeroCount=0,oneCount=0;
        for(int num:students)
        {
            if(num==0) zeroCount++;
            else oneCount++;
        }
        for(int num:sandwiches)
        {
            if(num==0 && zeroCount==0) return oneCount;
            if(num==1 && oneCount==0) return zeroCount;

            if(num==0) zeroCount--;
            else oneCount--;
        }
        return 0;
    }
};