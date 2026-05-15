class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[9][9] = {false};
        bool cols[9][9] = {false};
        bool parts[9][9] = {false};

        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == '.') continue;
                int a = board[i][j] - '1';
                if(a < 0 || a > 8) return false;
                int part = (i / 3) * 3 + (j / 3);
                if(rows[i][a]) return false;
                else rows[i][a] = true;
                if(cols[j][a]) return false;
                else cols[j][a] = true;
                if(parts[part][a]) return false;
                else parts[part][a] = true;
            }
        }
        return true;
    }
};