class Solution {
public:
    vector<string> res;
    void backtrack(string& current, int n, int starts, int ends) {
        if (starts == n && ends == n) {
            current += ')';
            res.push_back(current);
            current.pop_back();
            return;
        }
        if (ends < n && ends < starts + 1) {
            current += ')';
            backtrack(current, n, starts, ends + 1);
            current.pop_back();
        }
        if (starts < n) {
            current += '(';
            backtrack(current, n, starts + 1, ends);
            current.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string current = "(";
        backtrack(current, n - 1, 0, 0);
        return res;
    }
};