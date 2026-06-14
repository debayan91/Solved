class Solution {
public:
    void backtrack(vector<string>& current, vector<vector<string>>& res, int row){
        int n = current.size();
        if(row == n){
            res.push_back(current);
            return;
        }
        for(int col = 0; col < n; col++){
            bool flag = true;
            for(int i = row, j = col; i >= 0 && j >= 0 && flag; i--, j--){
                if(current[i][j] == 'Q'){
                    flag = false;
                }
            }
            if(!flag) continue;
            for(int i = row, j = col; i >= 0 && j < n && flag; i--, j++){
                if(current[i][j] == 'Q'){
                    flag = false;
                }
            }
            if(!flag) continue;
            for(int i = row; i >= 0 && flag; i--){
                if(current[i][col] == 'Q'){
                    flag = false;
                }
            }
            if(flag){
                current[row][col] = 'Q';
                backtrack(current, res, row + 1);
                current[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        string s = "";
        for(int i = 0; i < n; i++) s += '.';
        vector<string> current(n, s);
        backtrack(current, res, 0);
        return res;
    }
};