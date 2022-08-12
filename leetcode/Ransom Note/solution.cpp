class Solution {
public:
    /*
     * We use a hashmap to store the letters in magazine.
     * Next, we see if the letters are available for ransom Note.
     *
     * Time complexity - O(n + m) and Space complexity - O(m).
     */
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> letters;
        
        for (auto& c : magazine)
        {
            // Not found.
            if (letters.find(c) == letters.end())
            {
                letters[c] = 1;
            }
            else
            {
                letters[c]++;
            }
        }
        
        for (auto& c : ransomNote)
        {
            if (letters.find(c) == letters.end())
            {
                return false;
            }
            else
            {
                if (letters[c] <= 0) { return false; }
                letters[c]--;
            }
        }
        
        return true;
    }
};