class Solution {
public:
    
    bool dfs(vector<vector<char>>& board, string word, int i, int j, int index) {
        if (index == word.size()) {
            return true;
        }
        
        // Keep as temp backup.
        // We set the board with this value, so the same cell
        // cannot be used in the same path.
        char c = board[i][j];
        board[i][j] = '0';
        
        bool up = false;
        bool down = false;
        bool left = false;
        bool right = false;
        
        // Up.
        if (i > 0 && board[i - 1][j] == word[index]) {
            up = dfs(board, word, i - 1, j, index + 1);
        }
        
        // Down.
        if (i < board.size() - 1 && board[i + 1][j] == word[index]) {
            down = dfs(board, word, i + 1, j, index + 1);
        }
        
        // Left.
        if (j > 0 && board[i][j - 1] == word[index]) {
            left = dfs(board, word, i, j - 1, index + 1);
        }
        
        // Right.
        if (j < board[i].size() - 1 && board[i][j + 1] == word[index]) {
            right = dfs(board, word, i, j + 1, index + 1);
        }
        
        if (up || down || left || right) {
            return true;
        }
        
        // Set the cell back to its default value so it can be
        // used for another path in the future.
        board[i][j] = c;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == word[0]) {
                    // Search the board for the rest of the letters.
                    if (dfs(board, word, i, j, 1)) {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
};