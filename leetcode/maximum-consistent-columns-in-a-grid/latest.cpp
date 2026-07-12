class Solution {
public:
    int maxConsistentColumns(vector<vector<int>>& grid, int limit) {
        int m = size(grid);
        int n = size(grid[0]);
        vector<int> dp(n, 1);
        int res = 0;
        vector<vector<bool>> valid(n, vector<bool>(n, true)); // col * col
        for (int i = 0; i < m; i++) { // row
            for (int j = 0; j < n; j++) { // col
                for (int k = j + 1; k < n; k++) {
                    if(abs(grid[i][k] - grid[i][j]) > limit){
                        valid[j][k] = false;
                    }
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(valid[i][j]){
                    dp[j] = max(dp[j], dp[i] + 1);
                    res = max(res, dp[j]);
                }
            }
        }
        return max(res, 1);
    }
};