class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        int i=1,minCandies=1;
        while(i<n)
        {
            while(i<n && ratings[i]==ratings[i-1])
            {
                minCandies++;
                i++;
            }
            int peak=1;
            while(i<n && ratings[i]>ratings[i-1])
            {
                peak++;
                minCandies+=peak;
                i++;
            }
            int down=1;
            while(i<n && ratings[i]<ratings[i-1])
            {
                minCandies+=down;
                down++;
                i++;
            }
            if(down>peak)
            {
                minCandies+=(down-peak);
            }
        }
        return minCandies;
    }
};