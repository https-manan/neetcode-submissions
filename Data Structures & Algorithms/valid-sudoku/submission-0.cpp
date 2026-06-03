class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            unordered_map<char, int> row;
            unordered_map<char, int> col;

            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    row[board[i][j]]++;
                    if (row[board[i][j]] > 1)
                        return false;
                }

                if (board[j][i] != '.') {
                    col[board[j][i]]++;
                    if (col[board[j][i]] > 1)
                        return false;
                }
            }
        }
        for (int boxRow = 0; boxRow < 9; boxRow += 3) {
            for (int boxCol = 0; boxCol < 9; boxCol += 3) {
                unordered_map<char, int> box;

                for (int i = boxRow; i < boxRow + 3; i++) {
                    for (int j = boxCol; j < boxCol + 3; j++) {
                        if (board[i][j] == '.')
                            continue;

                        box[board[i][j]]++;

                        if (box[board[i][j]] > 1)
                            return false;
                    }
                }
            }
        }
        return true;
    }
};