class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& g) {
        int m = size(g);
        int n = size(g[0]);
        vector<vector<int>> dist(m, vector<int>(n, 1e5));
        vector<vector<bool>> v(m, vector<bool>(n, false));
        queue<array<int, 3>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (g[i][j] == 1) {
                    dist[i][j] = 0;
                    v[i][j] = true;
                    q.push({i, j, 0});
                }
            }
        }

        while (!q.empty()) {
            auto a = q.front();
            q.pop();
            int i = a[0];
            int j = a[1];
            int d = a[2];

            if (i - 1 >= 0 && i - 1 < m && j >= 0 && j < n &&
                dist[i - 1][j] == 1e5 && !v[i - 1][j]) {
                v[i - 1][j] = true;
                dist[i - 1][j] = d + 1;
                q.push({i - 1, j, d + 1});
            }

            if (i + 1 >= 0 && i + 1 < m && j >= 0 && j < n &&
                dist[i + 1][j] == 1e5 && !v[i + 1][j]) {
                v[i + 1][j] = true;
                dist[i + 1][j] = d + 1;
                q.push({i + 1, j, d + 1});
            }

            if (i >= 0 && i < m && j - 1 >= 0 && j - 1 < n &&
                dist[i][j - 1] == 1e5 && !v[i][j - 1]) {
                v[i][j - 1] = true;
                dist[i][j - 1] = d + 1;
                q.push({i, j - 1, d + 1});
            }

            if (i >= 0 && i < m && j + 1 >= 0 && j + 1 < n &&
                dist[i][j + 1] == 1e5 && !v[i][j + 1]) {
                v[i][j + 1] = true;
                dist[i][j + 1] = d + 1;
                q.push({i, j + 1, d + 1});
            }
        }

        return dist;
    }
};