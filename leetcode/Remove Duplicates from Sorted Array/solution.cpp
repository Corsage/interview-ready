class Solution {
public:

    /*
     * This solution takes advantage of the sorted array.
     * Uses a sliding window to see if nums[i] != nums[i + 1]
     * Keeps k as a counter to replace new values with.
     * 
     * Time complexity - O(n) and Space complexity - O(1).
     */
    int removeDuplicates(vector<int>& nums) {        
        int k = 1;
        
        // Array is already sorted.
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] != nums[i + 1]) {
                nums[k] = nums[i + 1];
                k++;
            }
        }
        
        return k;
    }

    /*
     * This solution actually removes duplicates in-place,
     * and returns the array with correct sizing.
     * 
     * Time complexity - O(n^2) and Space complexity - O(1).
     */
    int removeDuplicates(vector<int>& nums) {        
        auto start = nums.begin();
        
        while (start != nums.end()) {
            auto it = start + 1;
            
            while (it != nums.end()) {
                if (*start == *it) {
                    it = nums.erase(it);
                } else {
                    it++;
                }
            }
            
            start++;
        }
        
        return nums.size();
    }
};