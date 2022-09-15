class Solution {
public:

    /*
     * Indicies tell us what index of string s we need to check, but the index of the indicies is related to
     * the sources and targets. Thus, we create an unordered_map<int, int> to hold the index we need to 
     * check in s as well as its associated index in sources and targets.
     * 
     * if We need to check the index i.e. umap[i] exists, then we need to substr from s with sources[umap[i]].size()
     * compare the strings, and insert target if they match.
     * 
     * Time complexity - O(n) and Space complexity - O(n).
     */
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        string res = "";
        unordered_map<int, int> umap;
        
        for (int i = 0; i < indices.size(); i++) {
            umap[indices[i]] = i;
        }
        
        for (int i = 0; i < s.size(); i++) {
            if (umap.find(i) == umap.end()) {
                res += s[i];
                continue;
            }
            
            // Compare sources with s.
            string temp = s.substr(i, sources[umap[i]].size());
            
            if (temp == sources[umap[i]]) {
                res += targets[umap[i]];
            } else {
                res += temp;
            }
            
            i += temp.size() - 1;
        }
        
        return res;
    }

    /**
     * We keep an array of offsets to apply to each index as the index changes to the string
     * when a target replaces a source.
     * 
     * Time complexity - O(k * n) and Space complexity - O(n).
     */
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        int k = indices.size();
        int n = s.size();
        
        int offsets[n];
        memset(offsets, 0, sizeof(offsets));
        
        for (int i = 0; i < k; i++) {
            int index = indices[i];
            string src = sources[i];
            string tar = targets[i];
            
            // Check offsets.
            for (int j = 0; j < indices[i]; j++) {
                index += offsets[j];
            }
            
            bool found = true;
            for (int j = index; j < index + src.size(); j++) {
                if (s[j] != src[j - index]) {
                    found = false;
                    break;
                }
            }
            
            if (!found) { continue; }

            s.replace(index, src.size(), tar);
            offsets[indices[i]] = tar.size() - src.size();
        }
        
        return s;
    }
};