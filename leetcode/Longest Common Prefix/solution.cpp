class Solution {
public:
    
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        
        // Sort such that the largest difference in strings
        // will be at the front and back.
        sort(strs.begin(), strs.end());
        
        for (int i = 0; i < strs[0].size(); i++) {
            if (strs[0][i] == strs[strs.size() - 1][i]) {
                prefix += strs[0][i];
            } else {
                break;
            }
        }
        
        return prefix;
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        
        int i = 0;
        int j = 0;
        char c;
        
        
        while (j < strs[i].size()) {
            if (i == 0) {
                c = strs[i][j];
            } else {
                if (strs[i][j] != c) {
                    break;
                }
            }
            
            if (i == strs.size() - 1) {
                j++;
                i = 0;
                prefix += c;
            } else {
                i++;
            }
        }
        
        return prefix;
    }
};