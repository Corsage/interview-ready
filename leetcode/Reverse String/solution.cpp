class Solution {
public:
    /*
     * Very simple, since this is in-place reverse we have two pointers, i and j.
     * i starts at the beginning, j at the end, they swap.
     * i increments, j decrements and this continues until they have swapped everything.
     *
     * Time complexity - O(n) and Space complexity - O(1).
     */
    void reverseString(vector<char>& s) {
        int i = 0;
        int j = s.size() - 1;
        
        while (j > i)
        {
            char t = s[i];
            s[i] = s[j];
            s[j] = t;
            
            i++;
            j--;
        }
    }
};