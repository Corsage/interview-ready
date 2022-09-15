class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int time = 0;
        
        // Keep track where each garbage truck is at.
        int mi = 0;
        int pi = 0;
        int gi = 0;
        
        for (int i = 0; i < garbage.size(); i++) {
            // Garbage truck has to drive to the
            // house first, then pick up the things.
            if (garbage[i].find('M') != string::npos) {
                while (mi < i) {
                    time += travel[mi++];
                }
            }
            
            if (garbage[i].find('P') != string::npos) {
                while (pi < i) {
                    time += travel[pi++];
                }
            }
            
            if (garbage[i].find('G') != string::npos) {
                while (gi < i) {
                    time += travel[gi++];
                }
            }
            // Garbage trucks are at the required house.
            // Take all the garbage.
            time += garbage[i].size();
        }
        
        return time;
    }
};