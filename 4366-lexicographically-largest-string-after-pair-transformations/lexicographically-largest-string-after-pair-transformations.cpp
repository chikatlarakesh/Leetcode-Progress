class Solution {
public:
    vector<string> largestString(vector<int>& nums) {
        int n = nums.size();
        vector<string> result(n);

        for(int i=0;i<n;i++) {
            int count = nums[i];
            char ch = 'a';
            string sb = "";
            while(count > 0 && ch < 'z') {
                if(count % 2 == 1) {
                    sb += ch;
                }
                count /= 2;
                ch++;
            }

            if(count > 0) {
                sb.append(count, 'z');
            }
            reverse(sb.begin(), sb.end());
            result[i] = sb;
        }
        return result;
    }
};