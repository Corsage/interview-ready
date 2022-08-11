class Solution {
public:
    /*
     * This solution uses a 1D array instead of a usual 2D dp tabulation array.
     * Essentially, we create an array of length amount + 1.
     * There is only 1 way to have 0 coins!
     * Where each index represents the amount.
     * The value of the index reperesnts all the ways we can get to the amount.
     * We do dp[i] += dp[i - coin] where i = coin.
     *
     * Time complexity - O(n * m) and Space complexity - O(n).
     */
    int change(int amount, vector<int>& coins) {
        int dp[amount + 1];
        memset(dp, 0, sizeof(dp));
        
        dp[0] = 1;
        
        for (auto& coin : coins)
        {
            for (int i = coin; i < amount + 1; i++)
            {
                dp[i] += dp[i - coin];
            }
        }
        
        return dp[amount];
    }
};