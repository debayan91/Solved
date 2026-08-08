class Solution {
public:
    string shortestCommonSupersequence(string a, string b) {
        int m = size(a), n = size(b);
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (a[i - 1] == b[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] =
                        max({dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]});
                }
            }
        }
        string res = "";
        int i = m, j = n;
        while (i > 0 && j > 0) {
            if (a[i - 1] == b[j - 1]) {
                res += a[i - 1]; // if the characters match
                i--;
                j--;
            } else {
                // if they didnt
                if (dp[i][j] == dp[i - 1][j]) {
                    res += a[i - 1];
                    i--;
                } else {
                    res += b[j - 1];
                    j--;
                }
            }
        }
        while (i > 0) {
            res += a[i - 1];
            i--;
        }
        while (j > 0) {
            res += b[j - 1];
            j--;
        }
        reverse(begin(res), end(res));
        return res;
    }
};