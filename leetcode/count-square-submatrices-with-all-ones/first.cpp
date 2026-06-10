class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        int maxSide = 0;

        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1) {
                    dp[i][j] = 1;
                    count++;
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        int past = dp[i][j];
                        dp[i][j] = 1 + min({
                                           dp[i - 1][j],    // top
                                           dp[i][j - 1],    // left
                                           dp[i - 1][j - 1] // diagonal
                                       });
                        if (dp[i][j] != past) {
                            count += dp[i][j] - past;
                        }
                    }
                }
            }
        }
        return count;
    }
};