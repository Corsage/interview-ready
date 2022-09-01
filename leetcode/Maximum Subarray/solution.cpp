class Solution {
public:

    int maxSubArray(vector<int>& nums) {
        int res = numeric_limits<int>::min();
        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            res = max(sum, res);
            
            if (sum < 0) {
                sum = 0;
            }
        }
        
        return res;
    }
    
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int dp[n];
        
        // The greatest sum from [0, 0] is just nums[0].
        dp[0] = nums[0];
        
        int imax = dp[0];
        int icurr = dp[0];
        for (int i = 1; i < nums.size(); i++) {
            icurr += nums[i];
            icurr = max(icurr, nums[i]);
            
            imax = max(imax, icurr);
            dp[i] = imax;
        }
        
        return dp[n - 1];
    }
};