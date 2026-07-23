class Solution {
public:
    vector<vector<int>> dp;
    bool solve(int i, int j, string& s, string& p) {
        int n = s.size();
        int m = p.size();
        if (j == m) {     // end of string
            if (i == n) { // end of pattern
                return true;
            }
            return false;
        }
        if (dp[i][j] != -1) {
            return dp[i][j]; // already computed
        }
        bool currentCharactersMatch = false;
        if (i < n && (s[i] == p[j] || p[j] == '.')) {
            currentCharactersMatch = true; // current works
        }
        bool answer = false;
        if (j + 1 < m && p[j + 1] == '*') { // next
            bool skipCurrentCharacter = solve(i, j + 2, s, p);
            bool useCurrentCharacter = false;
            if (currentCharactersMatch) {
                useCurrentCharacter = solve(i + 1, j, s, p);
            }
            answer = skipCurrentCharacter || useCurrentCharacter;
        } else {
            if (currentCharactersMatch) {
                answer = solve(i + 1, j + 1, s, p);
            } else {
                answer = false;
            }
        }
        dp[i][j] = answer;
        return answer;
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        dp.assign(n + 1, vector<int>(m + 1, -1));
        return solve(0, 0, s, p);
    }
};