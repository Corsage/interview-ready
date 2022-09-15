class Solution {
public:
    int strStr(string haystack, string needle) {
        int res = -1;
        
        for (int i = 0; i < haystack.size(); i++) {
            // Match the first char.
            if (haystack[i] == needle[0]) {
                // Now try to match rest of the string.
                res = i;
                for (int j = i + 1; j < i + needle.size(); j++) {
                    if (haystack[j] != needle[j - i]) {
                        res = -1;
                        break;
                    }
                }
            }
            
            if (res != -1) { break; }
        }
        
        return res;
    }
};