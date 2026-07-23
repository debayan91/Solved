class Solution {
public:
    vector<vector<int>> dp;
    bool solve(int i, int j, string& s, string& p) {
        int n = s.size();
        int m = p.size();
        if (j == m) {     // end of pattern
            if (i == n) { // end of string
                return true;
            }
            return false;
        }
        if (dp[i][j] != -1) {
            return dp[i][j]; // already computed
        }
        bool answer = false;
        if (p[j] == '*') {
            bool skipStar = solve(i, j + 1, s, p); // skip the star index in the pattern
            // does this work out?
            bool consumeOneCharacter = false;
            if (i < n) {
                consumeOneCharacter = solve(i + 1, j, s, p); // the star takes one character 
                // does this work out?
            }
            answer = skipStar || consumeOneCharacter; // as long as one works out
        }
        else {
            bool currentCharactersMatch = false;
            if (i < n) {
                if (s[i] == p[j] || p[j] == '?') {
                    currentCharactersMatch = true; // ? == . of regex q
                }
            }
            if (currentCharactersMatch) {
                answer = solve(i + 1, j + 1, s, p); // does this work out
            }
            else {
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