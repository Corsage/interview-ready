class Solution {
public:
    /*
     * We have three pointers, i is at end nums1, j is at end of nums2, and
     * k is at the end of n + m array. We put the bigger number nums1[i] vs.
     * nums2[j] into nums1[k] and decrement. We add remaining for nums2
     * directly into nums1[k] if applicable since it's already sorted.
     * 
     * Time complexity - O(n + m) and Space complexity - O(1).
     */
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = n + m - 1;
        
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            } else {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }
        
        // Add remaining if needed.
        while (k >= 0 && j >= 0) {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
};