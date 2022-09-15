class Solution {
public:
    
    string itoa(int n, int base) {
        string res = "";
        
        while (n != 0) {
            int r = n % base;
            n /= base;
            res = to_string(r) + res;
        }
        
        return res;
    }
    
    bool isStrictlyPalindromic(int n) {
        int base = 2;
        
        while (base <= n - 2) {
            string s = itoa(n, base);
            string r(s.rbegin(), s.rend());
            
            if (s != r) {
                return false;
            }
            
            base++;
        }
        
        return true;
    }
};