class Solution {
public:
    /*
     * Simple solution, we add one and keep carrying forward until required.
     * If we care about the time complexity for vector insertion, we can add a
     * complete flag and just push_back the rest of the numbers.
     * 
     * Time complexity - O(n) and Space complexity - O(n).
     */
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res(digits);
        bool carry = false;
        
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] == 9) {
                carry = true;
                res[i] = 0;
            } else {
                carry = false;
                res[i] = digits[i] + 1;
                break;
            }
        }
        
        // Carry forward if whole number needs an additional digit.
        if (carry) {
            res.insert(res.begin(), 1);
        }
        
        return res;
    }
};