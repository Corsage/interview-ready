class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int cost = 0;
        
        // Simple greedy algorithm.
        pair<char, int> prev(colors[0], 0);
        
        for (int i = 1; i < colors.size(); i++) {
            if (colors[i] == prev.first) { 
                // Set the new balloon we compare to.
                if (neededTime[i] < neededTime[prev.second]) {
                    cost += neededTime[i];
                } else {
                    cost += neededTime[prev.second];
                    prev = pair(colors[i], i);
                }
            } else {
                prev = pair(colors[i], i);
            }
        }
        
        return cost;
    }
};