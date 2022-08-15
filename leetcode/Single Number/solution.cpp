class Solution {
public:
    /*
     * We sort the array first because then we know the structure
     * will be either [Y, X, X] or [X, X, Y, Z, Z] or [Z, Z, Y].
     * 
     * Time complexity - O(n) and Space complexity - O(1).
     */
    int singleNumber(vector<int>& nums) {
        if (nums.size() < 2) { 
            return nums[0];
        }
        
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i += 2) { 
            if (nums[i] != nums[i + 1]) {
                return nums[i];
            }
        }
        
        return nums[nums.size() - 1];
    }
};