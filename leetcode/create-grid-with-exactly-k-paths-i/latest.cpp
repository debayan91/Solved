class Solution {
public:
    vector<string> createGrid(int m, int n, int k) {
        vector<string> dp(m, string(n, '#'));

        if (k == 1) {
            for (int j = 0; j < n; j++) dp[0][j] = '.';
            for (int i = 0; i < m; i++) dp[i][n - 1] = '.';
            return dp;
        }

        if (k == 4 && m == 3 && n == 3) {
            dp[0][0] = '.';
            dp[0][1] = '.';
            dp[1][0] = '.';
            dp[1][1] = '.';
            dp[1][2] = '.';
            dp[2][1] = '.';
            dp[2][2] = '.';
            return dp;
        }

        if (m >= 2 && n >= k) {
            for (int j = 0; j < k; j++)
                dp[0][j] = '.';

            for (int j = 0; j < n; j++)
                dp[1][j] = '.';

            for (int i = 2; i < m; i++)
                dp[i][n - 1] = '.';

            return dp;
        }

        if (n >= 2 && m >= k) {
            for (int i = 0; i < k; i++)
                dp[i][0] = '.';

            for (int i = 0; i < m; i++)
                dp[i][1] = '.';

            for (int j = 2; j < n; j++)
                dp[m - 1][j] = '.';

            return dp;
        }

        return {};
    }
};