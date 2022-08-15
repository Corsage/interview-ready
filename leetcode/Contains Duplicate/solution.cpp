class Solution {
public:

    /*
     * We first sort the numbers and then use a sliding window
     * to see if nums[i] == nums[i + 1] which is a duplicate.
     * 
     * Time complexity - O(n) and Space complexity - O(1).
     */
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1]) { return true; }
        }
        
        return false;
    }

    /*
     * Use an unordered set, and see if it fails to insert.
     * Time complexity - O(n) and Space complexity - O(n).
     */
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> uset;
        
        for (auto& num : nums) {
            if (!uset.insert(num).second) {
                return true;
            }
        }
        
        return false;
    }
};