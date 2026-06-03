class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& dp) {
        int m = dp.size();
        int n = dp[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    if(dp[i][j] == 1){
                        return 0;
                    }
                    dp[i][j] = 1;
                    continue;
                }
                if (dp[i][j] == 1) {
                    // obstacle -> -1
                    dp[i][j] = -1;
                    continue;
                }
                int top = 0;
                int left = 0;
                if (i == 0) {
                    if (dp[i][j - 1] > 0) {
                        left = dp[i][j - 1];
                    }
                } else if (j == 0) {
                    if (dp[i - 1][j] > 0) {
                        top = dp[i - 1][j];
                    }
                } else {
                    if (dp[i - 1][j] > 0) {
                        top = dp[i - 1][j];
                    }
                    if (dp[i][j - 1] > 0) {
                        left = dp[i][j - 1];
                    }
                }
                dp[i][j] = top + left;
            }
        }
        return max(0, dp[m - 1][n - 1]);
    }
};