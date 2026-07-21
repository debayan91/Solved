class Solution {
public:
    int count = 0;
    void backtrack(vector<vector<int>>& grid, int i, int j,
                   vector<vector<bool>>& visited, int z, int vis) {
        int m = size(grid), n = size(grid[0]);
        if (i < 0 || j < 0 || i >= m || j >= n || visited[i][j] ||
            grid[i][j] == -1)
            return;
        if (grid[i][j] == 2 && vis == z) {
            count++;
            return;
        }
        visited[i][j] = true;
        backtrack(grid, i + 1, j, visited, z, vis + 1);
        backtrack(grid, i, j + 1, visited, z, vis + 1);
        backtrack(grid, i, j - 1, visited, z, vis + 1);
        backtrack(grid, i - 1, j, visited, z, vis + 1);
        visited[i][j] = false;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = size(grid), n = size(grid[0]);
        int z = 0, ii, jj;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) z++;
                if (grid[i][j] == 1){
                    ii = i;
                    jj = j;
                }
            }
        }
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        backtrack(grid, ii, jj, visited, z + 1, 0);
        return count;
    }
};