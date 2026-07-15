class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = size(grid);
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        dist[0][0] = grid[0][0];
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> pq;
        pq.push({grid[0][0], 0, 0});
        while (!pq.empty()) {
            auto [mx, i, j] = pq.top();
            pq.pop();
            if (mx > dist[i][j])
                continue;
            if (i > 0) {
                int d = max(grid[i - 1][j], mx);
                if (d < dist[i - 1][j]) {
                    dist[i - 1][j] = d;
                    pq.push({dist[i - 1][j], i - 1, j});
                }
            }

            if (j > 0) {
                int d = max(grid[i][j - 1], mx);
                if (d < dist[i][j - 1]) {
                    dist[i][j - 1] = d;
                    pq.push({dist[i][j - 1], i, j - 1});
                }
            }

            if (i < n - 1) {
                int d = max(grid[i + 1][j], mx);
                if (d < dist[i + 1][j]) {
                    dist[i + 1][j] = d;
                    pq.push({dist[i + 1][j], i + 1, j});
                }
            }

            if (j < n - 1) {
                int d = max(grid[i][j + 1], mx);
                if (d < dist[i][j + 1]) {
                    dist[i][j + 1] = d;
                    pq.push({dist[i][j + 1], i, j + 1});
                }
            }
        }
        return dist.back().back();
    }
};