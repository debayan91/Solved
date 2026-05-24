class Solution {

    // a b
    // c d

public:
    string wordie;
    bool res = false;
    int m,n;
    void dfs(vector<vector<char>>& board, int i, int j) {
        if (i < 0 || j < 0 || i > m - 1 || j > n - 1 || res)
            return;
        char c = board[i][j];
        if(board[i][j] == wordie.back()){
            wordie.pop_back();
            if(wordie.size() == 0){
                res = true;
                return;
            }
            board[i][j] = '*';
        }else{
            return;
        }

        dfs(board, i, j + 1);
        dfs(board, i, j - 1);
        dfs(board, i + 1, j);
        dfs(board, i - 1, j);

        board[i][j] = c;
        wordie.push_back(c);
    }

    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<char>> bard = board;
        reverse(word.begin(), word.end());

        wordie = word;

        int m = board.size();
        int n = board[0].size();

        this->m = m;
        this->n = n;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word.back()) {
                    // we found the start
                    dfs(board, i, j);
                    if(res) return res;
                    else{
                        wordie = word; // reset word
                        board = bard; // reset board
                    }
                }
            }
        }

        return false;
    }
};