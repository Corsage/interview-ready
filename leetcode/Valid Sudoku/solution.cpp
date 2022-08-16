class Solution {
public:
    /*
     * We check the row and col at the same time, and then put the element
     * in its associated square. If an insert fails, return false.
     * 
     * Time complexity - O(n * n) and Space complexity - O(n).
     */
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> squares(9);
        
        for (int i = 0; i < board.size(); i++) {
            unordered_set<char> row;
            unordered_set<char> col;
            
            for (int j = 0; j < board.size(); j++) {
                
                // Row.
                if (board[i][j] != '.') {
                    if (!row.insert(board[i][j]).second) {
                        return false;
                    }
                    
                    // Square - mapped with j and i.
                    int s = ((i / 3) * 3) + (j / 3);
                    if (!squares[s].insert(board[i][j]).second) {
                        return false;
                    }
                }
                
                if (board[j][i] != '.') {
                    // Column.
                    if (!col.insert(board[j][i]).second) {
                        return false;
                    }
                }
            }
        }
       
        
        return true;
    }
};