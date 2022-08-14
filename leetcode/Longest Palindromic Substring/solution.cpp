class Solution {
public:
    /*
     * A little bit of DP but this time without a n x n.
     * Optimizations are added by length to stop when needed.
     * 
     * Time complexity - O(n^2) and Space complexity - O(n).
     */
    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0;
        int len = 0;
        
        // Dynamic programming - we create a table size n.
        int dp[n];
        memset(dp, 0, sizeof dp);
        
        // Instead of using n x n table, we rewrite the same row.
        // if a better solution is found.
        for (int i = 0; i < n; i++) {
            
            // Stop if known answer is longer.
            if (len > n - i) { break; }
            
            for  (int j = 0; j < n; j++) {
                // Stop if known answer is longer.
                if (len > j - i) {
                    continue;
                }
                
                // Upper triangular matrix.
                else if (i <= j) {
                    if (s[i] == s[j]) {               
                        int x = i;
                        int y = j;
                        
                        // Potential problem:
                        // Keeps checking for long palindromes.
                        // "a" -> "aa" -> "aaa" -> "aaaa" all again.
                        while (x <= y) {
                            if (s[x] != s[y]) { break; }
                            x++;
                            y--;
                        }
                        
                        if (x > y) {
                            dp[i] = j - i + 1;
                        }
                    }
                }
                if  (dp[i] > len) {
                    len = dp[i];
                    start = i;
                }
            }
        }
        
        return s.substr(start, len);
    }
    
    /*
     * Naive solution - We test every substring and find the longest palindrome.
     * It is known that a string with length n has n^2 substrings.
     * We have to test each string if its a palindrome (O(n) time).
     * 
     * Time complexity - O(n^3) and Space complexity - O(1).
     */
    string longestPalindrome(string s) {
        string palindrome = "";
        
        // Naive solution - try every substring.
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < s.size() - i; j++) {
                string temp = s.substr(i, j + 1);
                
                // cout << "trying " << temp << endl;
                
                // Check if it's a palindrome.
                int start = 0;
                int end = temp.size() - 1;
                bool matches = true;
                
                while (start <= end) {
                    if (temp[start] != temp[end]) {
                        matches = false;
                        break;
                    }
                    
                    start++;
                    end--;
                }
                
                if (matches) {
                    if (temp.size() > palindrome.size()) {
                        palindrome = temp;
                    }
                }
            }
        }
        
        return palindrome;
    }
};