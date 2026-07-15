class Solution {
public:
    bool row[9][9] = {};
    bool col[9][9] = {};
    bool sector[9][9] = {};

    bool backtrack(vector<vector<char>>& board, int i, int j) {
        if (i == 9)
            return true;

        int ni = i;
        int nj = j + 1;
        if (nj == 9) {
            nj = 0;
            ni++;
        }

        if (board[i][j] != '.')
            return backtrack(board, ni, nj);

        int sec = (i / 3) * 3 + (j / 3);

        for (int num = 0; num < 9; num++) {
            if (row[i][num] || col[j][num] || sector[sec][num])
                continue;

            row[i][num] = true;
            col[j][num] = true;
            sector[sec][num] = true;
            board[i][j] = char('1' + num);

            if (backtrack(board, ni, nj))
                return true;

            row[i][num] = false;
            col[j][num] = false;
            sector[sec][num] = false;
            board[i][j] = '.';
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.')
                    continue;

                int num = board[i][j] - '1';
                int sec = (i / 3) * 3 + (j / 3);

                row[i][num] = true;
                col[j][num] = true;
                sector[sec][num] = true;
            }
        }

        backtrack(board, 0, 0);
    }
};