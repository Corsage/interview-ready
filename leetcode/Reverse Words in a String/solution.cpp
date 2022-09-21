class Solution {
public:
    string reverseWords(string s) {
        string res = "";
        stack<string> words;
        
        stringstream ss(s);
        string word;
        while (getline(ss, word, ' ')) {
            // Ignore spaces.
            if (word.find_first_not_of(' ') != string::npos) {
                words.push(word);
            }
        }
        
        // Since stack is FIFO, by popping the words one-by-one,
        // it'll automatically be in reverse order.
        while (!words.empty()) {
            res += words.top();
            words.pop();
            
            if (!words.empty()) {
                res += " ";
            }
        }
        
        return res;
    }

    string reverseWords(string s) {
        string res = "";
        
        stringstream ss(s);
        string word;
        while (getline(ss, word, ' ')) {
            // Ignore spaces.
            if (word.find_first_not_of(' ') != string::npos) {
                res = word + " " + res;
            }
        }
        
        // Have extra space at the end.
        res.pop_back();
        return res;
    }
};