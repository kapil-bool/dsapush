class Solution {
public:
    vector<pair<int, int>> direction = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}}; // down, up, left, right

    bool helper(int index, vector<vector<char>>& board, string& word, int row, int col) {
        int r = board.size();
        int c = board[0].size();
        if (index == word.size()) return true;
        if (row < 0 || col < 0 || row >= r || col >= c || board[row][col] != word[index])
            return false;

        char temp = board[row][col];
        board[row][col] = '#'; // mark as visited

        for (auto &[dx, dy] : direction) {
            int new_r = row + dx;
            int new_c = col + dy;
            if (helper(index + 1, board, word, new_r, new_c)) {
                return true;
            }
        }

        board[row][col] = temp; // backtrack
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int r = board.size();
        int c = board[0].size();

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (helper(0, board, word, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }
};
