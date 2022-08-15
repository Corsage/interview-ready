class Solution {
public:

    /*
     * If we sort the given arrays first, then we can find the
     * matching elements by going through them with pointers,
     * only increasing i if nums1[i] < nums2[j] and only 
     * only increasing j if nums1[i] > nums2[j].
     * 
     * Time complexity - O(n log n) and Time complexity - O(1).
     */
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        
        // Sort the arrays.
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        // Use two pointers.
        int i = 0;
        int j = 0;
        
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                res.push_back(nums1[i]);
                i++;
                j++;
            } else if (nums1[i] > nums2[j]) {
                j++;
            } else {
                i++;
            }
        }
        
        return res;
    }
    
    /*
     * We use a map to keep track of how many of ea number
     * there is, and then decrease as we go through the
     * second vector, adding common elements to resultant.
     * 
     * Time complexity - O(n + m) and Space complexity - O(n + m).
     */
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> umap;
        vector<int> res;
        
        // Base case.
        if (nums1.empty()) {
            return nums2;
        } else if (nums2.empty()) {
            return nums1;
        }
        
        for (int i = 0; i < nums1.size(); i++) {
            umap[nums1[i]]++;
        }
        
        for (int i = 0; i < nums2.size(); i++) {
            if (umap.find(nums2[i]) != umap.end()) {
                if (umap[nums2[i]] > 0) {
                    res.push_back(nums2[i]);
                    umap[nums2[i]]--;
                }
            }
        }
        
        return res;
    }
};