class Solution {
public:

    /*
     * From discussion someone mentioned a two pointer solution,
     * this is what I came up with.
     * 
     * Time complexity - O(n) and Space complexity - O(1).
     */
    int rob(vector<int>& nums) {
        int curr = 0;
        int prev = 0;
        int curr_max;
        
        for (int i = 0; i < nums.size(); i++) {
            curr_max = max(nums[i] + prev, curr);
            prev = curr;
            curr = curr_max;
        }
        
        return curr_max;
    }

    /*
     * We use DP with a 1D arr, to keep track of max values.
     *
     * Time complexity - O(n) and Space complexity - O(n).
     */
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if (n == 1) {
            return nums[0];
        }
        
        int dp[n];
        dp[0] = nums[0];
        dp[1] = nums[1];
        
        int curr_max = dp[0];
        
        for (int i = 2; i < nums.size(); i++) {
                        
            if (dp[i - 2] > curr_max) {
                curr_max = dp[i - 2];
            }
            
            dp[i] = nums[i] + curr_max;
        }
        
        return max(dp[n - 2], dp[n - 1]);
    }
};