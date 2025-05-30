class Solution {
    private:
    class comparer{
        public:
        bool operator()(vector<int>& a,vector<int>& b)
        {
            return a[1]>b[1];
        }
    };
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),comparer());
        int maxUnits=0;
        for(const vector<int>& box:boxTypes)
        {
            int boxes=box[0];
            int units=box[1];
            if(boxes<=truckSize)
            {
                int total=boxes*units;
                maxUnits+=total;
                truckSize-=boxes;
            }
            else
            {
                int total=truckSize*units;
                maxUnits+=total;
                break;
            }
        }
        return maxUnits;
    }
};