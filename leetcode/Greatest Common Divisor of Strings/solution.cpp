class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int x = gcd(str1.size(), str2.size());
        
        // Test to ensure substr x actually divides them.
        string xs = str1.substr(0, x);
        
        for (int i = x; i < str1.size(); i += x) {
            string temp = str1.substr(i, x);

            if (temp != xs) {
                return "";
            }
        }
        
        for (int i = 0; i < str2.size(); i += x) {
            string temp = str2.substr(i, x);
            
            if (temp != xs) {
                return "";
            }
        }
        
        return xs;
    }
};