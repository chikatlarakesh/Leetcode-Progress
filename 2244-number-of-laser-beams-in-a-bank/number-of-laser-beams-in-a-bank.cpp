class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        int m = bank[0].size();
        vector<int> totalDevices;
        for(int i=0;i<n;i++) {
            int devices = 0;
            for(int j=0;j<m;j++) {
                if(bank[i][j] == '1') devices++;
            }
            if(devices > 0) totalDevices.push_back(devices);
        }

        if(totalDevices.size() == 1) return 0;

        int size = totalDevices.size();
        int laserBeams = 0;
        for(int i=0;i<size-1;i++) {
            laserBeams += totalDevices[i] * totalDevices[i+1];
        } 
        return laserBeams;
    }
};