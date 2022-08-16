class Solution {
public:
    /*
     * Greedy solution - with sliding window we keep buying one day and then
     * sell the next only if prices[next] > prices[prev].
     * 
     * Time complexity - O(n) and Space complexity - O(1).
     */
    int maxProfit(vector<int>& prices) {
        int gains = 0;
        
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i - 1] < prices[i]) {
                gains = gains + prices[i] - prices[i - 1];
            }
        }
        
        return gains;
    }

    /*
     * Dynamic Programming solution, we consider a 2D array.
     * The array[i - 1][j - 1] holds the best profit made from the
     * previous day. We try to find the max profit by end of 
     * the day.
     * 
     * Time complexity - O(n^2) and Space complexity - O(n^2).
     */
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dp[n][n];
        memset(dp, 0, sizeof dp);
        
        // Consider only day 1.
        for (int i = 0; i < n; i++) {
            dp[0][i] = max(0, prices[i] - prices[0]);
        }
        
        // Buying and selling on same day is always 0.
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < n; j++) {
                
                if (i >= j) {
                    dp[i][j] = max(0, dp[i - 1][j]);
                } else {
                    int today = max(0, prices[j] - prices[i]) + dp[i - 1][j - 1];
                    dp[i][j] = max(today, dp[i][j - 1]);
                }
            }
        }
        
        return dp[n - 1][n - 1];
    }
};