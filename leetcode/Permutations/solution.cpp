class Solution {
public:

    /*
     * Following recursion design we do the usual, We swap elements instead.
     * We keep track of swaps as like an index so we only do unique swaps.
     *
     * Time complexity - O(n) and Space complexity - O(n).
     */
    void rPermute(vector<int> nums, int swaps, vector<vector<int>>& res)
    {
        // Base case.
        if (swaps == nums.size())
        {
            res.push_back(nums);
            return;
        }
        
        // Recursive case.
        for (int i = swaps; i < nums.size(); i++)
        {
            swap(nums[i], nums[swaps]);
            rPermute(nums, swaps + 1, res);
            swap(nums[i], nums[swaps]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        
        rPermute(nums, 0, res);
        return res;
    }

    /*
     * Following recursion design we do the usual, but I remove the element from nums after,
     * so that the element can only be used once.
     *
     * Time complexity - O(n) and Space complexity - O(2n)
     */
    void rPermute(vector<int> nums, vector<int>& temp, vector<vector<int>>& res)
    {
        // Base case.
        if (nums.size() == 0)
        {
            res.push_back(temp);
            return;
        }
        
        // Recursive case.
        for (int j = 0; j < nums.size(); j++)
        {
            temp.push_back(nums[j]);
            vector<int> nums2 = vector<int>(nums);
            nums2.erase(nums2.begin() + j);
            rPermute(nums2, temp, res);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        
        rPermute(nums, temp, res);
        return res;
    }
};