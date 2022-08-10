class Solution {
public:
    /*
     * Initial Logic:
     * Find the missing number in the array by continously searching and incrementing.
     * However this seems very tedious and long.
     *
     * Optimized Solution:
     * Sum up the array, and compare it against the what the sum should be.
     * The difference between the two is the missing number.
     *
     * Time complexity - O(n) and Space complexity - O(1).
     */
     
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        int _sum = nums.size();
        
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            _sum += i;
        }
        
        
        return _sum - sum;
    }
};