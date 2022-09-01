class Solution {
public:

    /**
     * We use DP to solve this question, where dp[i][j] represents the
     * number of numbers to take from nums1 and nums2. For example,
     * i = 1, j = 3, means 1 number from nums1, 3 numbers from nums2.
     * 
     * We check nums1, one number at a time to all the numbers in nums2.
     * If a match is found, then we take the dp[i - 1][j - 1] + 1
     * Else, we take the max(dp[i - 1][j], dp[i][j - 1])
     * 
     * Time complexity - O(n * m) and Space complexity - O(n * m).
     */ 
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        
        int dp[n + 1][m + 1];
        memset(dp, 0, sizeof(dp));
        
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        return dp[n][m];
    }
};