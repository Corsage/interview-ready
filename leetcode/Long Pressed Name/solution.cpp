class Solution {
public:
    /*
     * We use a two pointer solution, one for name, and one for typed.
     * We keep track of counts (ci, cj) of each letter.
     * In general we create the following rules.
     * cj >= ci and that name[i] == typed[j].
     * 
     * Since typed must be name but with repeating characters
     * in the same order as name.
     * 
     * Time complexity - O(n + m) and Space complexity - O(1).
     */
    bool isLongPressedName(string name, string typed) {
        int i = 0;
        int j = 0;
        int ci = 1;
        int cj = 1;
        
        while (i < name.size() || j < typed.size()) {
            while (i + 1 < name.size() && name[i] == name[i + 1]) {
                i++;
                ci++;
            }
            
            while (j + 1 < typed.size() && typed[j] == typed[j + 1]) {
                j++;
                cj++;
            }
            
            if (name[i] != typed[j] || cj < ci) {
                return false;
            }
            
            i++;
            j++;
            ci = 1;
            cj = 1;
        }
        
        return true;
    }

    /*
     * My original solution, instead of using ci, cj I check prev i - 1, j - 1.
     * The solution ends up looking a bit more complicated so I think the top one
     * is more readable.
     * 
     * Time complexity - O(n + m) and Space complexity - O(1).
     */
    bool isLongPressedName(string name, string typed) {
        int i = 0;
        int j = 0;
        
        // Base case - typed must always be equal or greater.
        if (typed.size() < name.size()) {
            return false;
        }
        
        while (i < name.size() && j < typed.size()) {
            if (name[i] == typed[j]) {
                i++;
                j++;
            } else if (i > 0 && j > 0) {
                if (name[i - 1] == typed[j]) {
                    j++;
                } else {
                    return false;
                }
            } else {
                return false;
            }
        }
        
        // Check remaining of typed if needed.
        while (j < typed.size()) {
            if (name[name.size() - 1] != typed[j]) {
                return false;
            }
            
            j++;
        }
        
        return i == name.size();
    }
};