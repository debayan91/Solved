class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = size(grid), n = size(grid[0]);
        vector<int> a(m, 0), b(n, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)
                if (grid[i][j]) {
                    a[i]++;
                    b[j]++;
                }
        }
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] && (a[i] > 1 || b[j] > 1))
                    count++;
            }
        }
        return count;
    }
};