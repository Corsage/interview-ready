class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int dp[n];
        
        for (int i = 0; i < cost.size(); i++) {
            if (i == 0 || i == 1) {
                dp[i] = cost[i];
            } else {
                int s1 = cost[i] + dp[i - 1];
                int s2 = cost[i] + dp[i - 2];
                dp[i] = min(s1, s2);
            }
        }
        
        return min(dp[n - 1], dp[n - 2]);
    }
};