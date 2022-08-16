class Solution {
public:
    /*
     * This is a two pointer approach to minimize operations.
     * We iterate throught the list and find where the last zero is (j).
     * Then, we set the zeros at the end accordingly.
     * 
     * Time complexity - O(n) and Space complexity - O(1).
     */
    void moveZeroes(vector<int>& nums) {
        
        int j = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0) {
                nums[j] = nums[i];
                j++;
            }
        }
        
        for (int i = j; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};