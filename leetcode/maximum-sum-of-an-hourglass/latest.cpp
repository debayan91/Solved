class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int m = size(grid);
        int n = size(grid[0]);
        if(m < 3 || n < 3) return -1;
        int mr = m - 3;
        int nr = n - 3;
        int mx = 0;
        for(int i = 0; i <= mr; i++){
            for(int j = 0; j <= nr; j++){
                int sum = grid[i][j] + grid[i][j + 1] + grid[i][j + 2] + grid[i + 1][j + 1] + grid[i + 2][j] + grid[i + 2][j + 1] + grid[i + 2][j + 2];
                mx = max(mx, sum);
            }
        }
        return mx;
    }
};