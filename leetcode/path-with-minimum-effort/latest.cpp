class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& h) {
        int m = size(h);
        int n = size(h[0]);
        vector<vector<int>> diff(m, vector<int>(n, INT_MAX));
        diff[0][0] = 0;
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> pq;
        pq.push({0, 0, 0}); // difference, i, j

        while (!pq.empty()) {
            auto [d, i, j] = pq.top();
            pq.pop();

            if (d > diff[i][j])
                continue;

            if (i > 0) {
                int x = i - 1;
                int y = j;
                int w = abs(h[x][y] - h[i][j]);
                int nd = max(d, w);
                if (nd < diff[x][y]) {
                    diff[x][y] = nd;
                    pq.push({diff[x][y], x, y});
                }
            }

            if (j > 0) {
                int x = i;
                int y = j - 1;
                int w = abs(h[x][y] - h[i][j]);
                int nd = max(d, w);
                if (nd < diff[x][y]) {
                    diff[x][y] = nd;
                    pq.push({diff[x][y], x, y});
                }
            }

            if (i < m - 1) {
                int x = i + 1;
                int y = j;
                int w = abs(h[x][y] - h[i][j]);
                int nd = max(d, w);
                if (nd < diff[x][y]) {
                    diff[x][y] = nd;
                    pq.push({diff[x][y], x, y});
                }
            }

            if (j < n - 1) {
                int x = i;
                int y = j + 1;
                int w = abs(h[x][y] - h[i][j]);
                int nd = max(d, w);
                if (nd < diff[x][y]) {
                    diff[x][y] = nd;
                    pq.push({diff[x][y], x, y});
                }
            }
        }

        return diff.back().back();
    }
};