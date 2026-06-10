class Solution {
public:
    void dfs(vector<vector<char>>& board, int i, int j) {
        if (i < 0 || i >= size(board) || j < 0 || j >= size(board[0]) || board[i][j] != 'O') {
            return;
        }

        board[i][j] = '#';

        dfs(board, i - 1, j);
        dfs(board, i + 1, j);
        dfs(board, i, j + 1);
        dfs(board, i, j - 1);
    }

    void solve(vector<vector<char>>& board) {
        int m = size(board);
        int n = size(board[0]);

        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') dfs(board, i, 0);
        }

        for (int i = 0; i < m; i++) {
            if (board[i][n - 1] == 'O') dfs(board, i, n - 1);
        }

        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O') dfs(board, 0, j);
        }

        for (int j = 0; j < n; j++) {
            if (board[m - 1][j] == 'O') dfs(board, m - 1, j);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};