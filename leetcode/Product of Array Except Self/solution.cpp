class Solution {
public:
    /*
     * We introduce two arrays, prefix and postfix to answer the question.
     * If we have to find the product of the all the elements in the array
     * without n, we consider the products all before n (prefix) and all
     * the elements after n (postfix).
     * 
     * To do this, we go through the nums array twice, once from 0 - n
     * and then from n - 0. We are able to find n via
     * prefix[n - 1] * postfix[n + 1];
     * 
     * Time complexity - O(n) and Space complexity - O(n).
     */
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        
        // Prefix and postfix.
        int prefix[n];
        int postfix[n];
        
        prefix[0] = nums[0];
        postfix[n - 1] = nums[n - 1];
        
        int i = 1;
        int j = n - 2;
        while (i < n && j >= 0) {
            prefix[i] = prefix[i - 1] * nums[i];
            postfix[j] = postfix[j + 1] * nums[j];
            
            i++;
            j--;
        }
        
        for (int k = 0; k < n; k++) {
            int p = k > 0 ? prefix[k - 1] : 1;
            int q = k < n - 1 ? postfix[k + 1] : 1;
            res[k] = p * q;
        }
        
        return res;
    }
};