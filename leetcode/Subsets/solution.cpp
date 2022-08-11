class Solution {
public:
    /*
     * We want to return all POSSIBLE subsets, so we consider recursion.
     * Note: Given n elements the powerset always contains 2^n elements.
     * We want to add each element on its own first, aka the for loop.
     * But after we want to recursive call the function with an increased index
     * to continue from the next element forward. i.e. 1 -> 1, 2 -> 1, 3 
     * Then from 1, 2 -> 1, 2, 3 then 2 -> 2, 3, and lastly 3.
     *
     * Time complexity - O(2^n) and Space complexity - O(2^n).
     */
    void rSubsets(vector<int>& nums, int i, vector<int>& temp, vector<vector<int>>& res)
    {
        // Base case i.e. [].
        res.push_back(temp);
        
        // Recursive case.
        for (int j = i; j < nums.size(); j++)
        {
            temp.push_back(nums[j]);
            
            rSubsets(nums, j + 1, temp, res);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> res;
        rSubsets(nums, 0, temp, res);
        
        return res;
    }
};