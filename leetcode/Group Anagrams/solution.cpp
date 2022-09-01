class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> umap;
        
        for (auto& str : strs) {
            string s = str;
            sort(s.begin(), s.end());
            umap[s].push_back(str);
        }
        
        vector<vector<string>> res;
        res.reserve(umap.size());
        
        for (auto& pair : umap) {
            res.push_back(pair.second);
        }
        
        return res;
    }
    
    /*
     * Two strings are anagrams if their sorted strings are equal.
     * We use this to our advantage by using the sorted string as
     * a key for our unordered_map.
     * 
     * The unordered map has the sorted anagram string key and
     * its associated index in res as the value.
     * 
     * Time complexity - O(n log n) and Space complexity - O(n).
     */
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, int> umap;
        
        int iRes = 0;
        for (auto& str : strs) {
            string s = str;
            sort(s.begin(), s.end());
            
            if (umap.find(s) != umap.end()) {
                // Anagram exists already.
                res[umap[s]].push_back(str);
            } else {
                umap[s] = iRes;
                res.push_back(vector<string> { str });
                iRes++;
            }
        }
        
        return res;
    }
};