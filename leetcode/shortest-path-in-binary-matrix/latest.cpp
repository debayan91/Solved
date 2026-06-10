class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return -1;
        }

        queue<vector<int>> q;
        q.push({0, 0, 1}); // row, col, distance
        grid[0][0] = 1;    // visited

        while (!q.empty()) {
            int i = q.front()[0];
            int j = q.front()[1];
            int dist = q.front()[2];
            q.pop();

            if (i == n - 1 && j == n - 1) {
                return dist;
            }

            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {
                    if (di == 0 && dj == 0) continue;

                    int ni = i + di;
                    int nj = j + dj;

                    if (ni >= 0 && ni < n && nj >= 0 && nj < n && grid[ni][nj] == 0) {
                        grid[ni][nj] = 1; // visited before pushing
                        q.push({ni, nj, dist + 1});
                    }
                }
            }
        }

        return -1;
    }
};