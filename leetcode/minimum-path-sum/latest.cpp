class Solution {
public:
    int minPathSum(vector<vector<int>>& dp) {
        int m = size(dp);
        int n = size(dp[0]);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i + j == 0) continue;
                if(i == 0){
                    dp[i][j] += dp[i][j - 1];
                }else if(j == 0){
                    dp[i][j] += dp[i - 1][j];
                }else{
                    dp[i][j] += min(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};