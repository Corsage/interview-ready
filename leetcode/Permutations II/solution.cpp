class Solution {
public:
    
    /*
     * Take Permutations I solution but add a set to get unique ones.
     *
     * Time complexity - O(2^n) and Space complexity - O(2^n).
     */
    void rPermuteUnique(vector<int> nums, int swaps, set<vector<int>>& res)
    {
        // Base case.
        if (swaps == nums.size())
        {
            res.insert(nums);
            return;
        }
        
        // Recursive case.
        for (int i = swaps; i < nums.size(); i++)
        {
            swap(nums[i], nums[swaps]);
            rPermuteUnique(nums, swaps + 1, res);
            swap(nums[i], nums[swaps]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> res;
        rPermuteUnique(nums, 0, res);
        
        vector<vector<int>> out(res.begin(), res.end());
        return out;
    }
};