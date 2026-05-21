class Solution {
public:
    int maxarea = 0;
    int area;
    void dfs(vector<vector<int>>& grid, int n, int m, int i, int j) {
        if (i < 0 || i >= n || j < 0 || j >= m)
            return;
        if (grid[i][j] == 1) {
            grid[i][j] = 0;
            area++;
            maxarea = area > maxarea ? area : maxarea;
        } else
            return;
        dfs(grid, n, m, i + 1, j);
        dfs(grid, n, m, i - 1, j);
        dfs(grid, n, m, i, j + 1);
        dfs(grid, n, m, i, j - 1);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    area = 0;
                    dfs(grid, n, m, i, j);
                }
            }
        }
        return maxarea;
    }
};