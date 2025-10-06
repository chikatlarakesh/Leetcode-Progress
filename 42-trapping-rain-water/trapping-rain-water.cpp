class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> pge(n,-1), nge(n,-1);

        int prefix = height[0];
        for(int i = 1;i < n ;i++) {
            if(prefix > height[i]) {
                pge[i] = prefix;
            }
            prefix = max(prefix,height[i]);
        }

        int suffix = height[n-1];
        for(int i=n-2;i>=0;i--) {
            if(suffix > height[i]) {
                nge[i] = suffix;
            }
            suffix = max(suffix,height[i]);
        }

        int result = 0;
        for(int i=0;i<n;i++) {
            if(pge[i] != -1 && nge[i] != -1) {
                result += min(pge[i],nge[i]) - height[i];
            }
        }
        return result;
    }
};