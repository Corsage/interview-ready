class Solution {
public:
    /*
     * We sort the wordDict vector first for optimization in larger lists.
     * The queue keeps track of all the indexes we want to "start from" for string s.
     * This is why index 0 is pushed first.
     * Next, we keep a visited vector so we don't revisit the same index
     * i.e. two words fit and end up taking the same index so you substr twice from there.
     * Next, we go through the words and find whatever fits substr i to word.size().
     * Push the future index to check into the queue.
     *
     * Time complexity and Space complexity I'm not sure but looks like less than O(n^2).
     */
    bool wordBreak(string s, vector<string>& wordDict)
    {
        // Sort wordDict by length of string.
        sort(wordDict.begin(), wordDict.end(), [](string a, string b) {
            return a.size() < b.size();
        });
        
        // Start at the index 0 in string s.
        queue<int> q;
        q.push(0);
        
        // DP - Keep track of previously visited indexes.
        vector<bool> visited(s.size());
        
        while (!q.empty())
        {
            // Retrieve current index in string s.
            int i = q.front();
            q.pop();
            
            int len = s.size() - i;
            
            // Reached the end of string s.
            if (len == 0) { return true; }
            
            if (visited[i]) { continue; }
            visited[i] = true;
            
            for (auto& word : wordDict)
            {
                if (word.size() <= len && s.substr(i, word.size()) == word && !visited[i + word.size()])
                {
                    q.push(i + word.size());
                }
            }
        }
        
        return false;
    }
};