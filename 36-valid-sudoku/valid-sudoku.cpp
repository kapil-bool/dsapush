class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            unordered_set<char> row, col, box;
            for (int j = 0; j < 9; j++) {
                // Row check
                if (board[i][j] != '.') {
                    if (row.count(board[i][j])) return false;
                    row.insert(board[i][j]);
                }

                // Column check
                if (board[j][i] != '.') {
                    if (col.count(board[j][i])) return false;
                    col.insert(board[j][i]);
                }

                // Box check
                int rowIndex = 3 * (i / 3);
                int colIndex = 3 * (i % 3);
                char ch = board[rowIndex + j / 3][colIndex + j % 3];
                if (ch != '.') {
                    if (box.count(ch)) return false;
                    box.insert(ch);
                }
            }
        }
        return true;
    }
};
