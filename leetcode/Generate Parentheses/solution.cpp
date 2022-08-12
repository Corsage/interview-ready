class Solution {
public:

    /*
     * Generating combinations question - we use recursion.
     * We keep track of left and right braces, where we can only
     * add a right brace if a left brace is present (i.e. l > r).
     * We can add up to n left braces but the right braces must be
     * positioned correctly, using the l > r rule.
     *
     * Time complexity - O(2^n) and Space complexity - O(2^n).
     */
    void rGenerateParentheses(string temp, int l, int r, int max, vector<string>& res)
    {
        // Base case.
        if (l == max && r == max)
        { 
            res.push_back(temp);
            return;
        }
        
        if (l < max)
        {
            rGenerateParentheses(temp + "(", l + 1, r, max, res);
        }
        
        if (l > r)
        {
             rGenerateParentheses(temp + ")", l, r + 1, max, res);
        }
    }
    
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        rGenerateParentheses("", 0, 0, n, res);
        
        return res;
    }
};