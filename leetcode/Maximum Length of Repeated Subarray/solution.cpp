class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int res = 0;
        
        int n = nums1.size();
        int m = nums2.size();
        
        int dp[n][m];
        memset(dp, 0, sizeof(dp));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (nums1[i] == nums2[j]) {
                    if (i > 0 && j > 0) {
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    } else {
                        dp[i][j]++;
                    }
                    
                    res = max(res, dp[i][j]);
                }
            }
        }
        
        return res;
    }
};