class Solution {
public:

    /*
     * Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?
     */
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        
        unordered_map<wchar_t, int> umap;
        
        for (int i = 0; i < s.size(); i++) {
            umap[s[i]]++;
        }
        
        for (int i = 0; i < t.size(); i++) {
            if (umap.find(t[i]) == umap.end() || --umap[t[i]] < 0) {
                return false;
            }
        }
        
        return true;
    }

    /*
     * This solution only works if s and t consist of lowercase English letters only.
     * We create an array and map the characters to their index, increasing the val.
     * Then subtract the val with the next string, then check if it's 0 or not.
     * 
     * Time complexity - O(n + m) and Space complexity - O(1).
     */
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        
        int arr[26] = { 0 };
        
        for (int i = 0; i < s.size(); i++) {
            arr[s[i] - 'a']++; 
        }
        
        for (int i = 0; i < t.size(); i++) {
            arr[t[i] - 'a']--; 
        }
        
        for (int i = 0; i < 26; i++) {
            if (arr[i] != 0) { 
                return false;
            }
        }
        
        return true;
    }
};