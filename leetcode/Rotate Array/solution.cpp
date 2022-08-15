class Solution {
public:

    /*
     * This solution is in-place. We do 3 reverses.
     * Given the example, nums = [1,2,3,4,5,6,7], k = 3
     * We perform the following 3 reverses.
     * [7, 6, 5, 4, 3, 2, 1]
     * [5, 6, 7, 4, 3, 2, 1]
     * [5, 6, 7, 1, 2, 3, 4] <-- answer
     * 
     * Time complexity - O(2n) and Space complexity - O(1).
     */
    void reverse(vector<int>& nums, int start, int end) {
        int i = start;
        int j = end;
        
        while (i < j) {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }
    
    void rotate(vector<int>& nums, int k) {
        int n = k % nums.size();
        
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, n - 1);
        reverse(nums, n, nums.size() - 1);
    }

    /*
     * We map the indexes based on the rotation k.
     * Time complexity - O(n) and Space complexity - O(n).
     */
    void rotate(vector<int>& nums, int k) {
        vector<int> arr(nums.size());
        
        for (int i = 0; i < nums.size(); i++) {
            arr[(i + k) % nums.size()] = nums[i];
        }
        
        nums = arr;
    }
};