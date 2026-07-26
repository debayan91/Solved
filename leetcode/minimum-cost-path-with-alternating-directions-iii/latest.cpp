class Solution {
public:
    long long minCost(int m, int n, vector<vector<int>>& p) {
        // djikstra
        vector < vector<array<long long, 2>>> dist(m, vector<array<long long, 2>>(n, {LLONG_MAX, LLONG_MAX}));
        // -> odd / even and dist
        priority_queue<array<long long, 4>, vector<array<long long, 4>>,greater<>>pq;
        long long start = dist[0][0][1] = 1;
        pq.push({start, 0, 0, 1}); // cost, i, j, odd / even
        while (!pq.empty()) {
            auto [c, i, j, x] = pq.top();
            pq.pop();
            if (i == m - 1 && j == n - 1)
                return c;
            if (c > dist[i][j][x])
                continue;
            // if i choose to wait
            if (c + p[i][j] < dist[i][j][1 - x]) {
                dist[i][j][1 - x] = c + p[i][j];
                pq.push({dist[i][j][1 - x], i, j, 1 - x});
            }
            // else
            if (i + 1 < m) { // down
                long long current = (i + 2) * (j + 1);
                long long next = c + current + (x == 0 ? p[i][j] : 0);
                if (next < dist[i + 1][j][1 - x]) {
                    dist[i + 1][j][1 - x] = next;
                    pq.push({next, i + 1, j, 1 - x});
                }
            }
            if (i - 1 >= 0) { // up
                long long current = (i) * (j + 1);
                long long next = c + current + (x == 1 ? p[i][j] : 0);
                if (next < dist[i - 1][j][1 - x]) {
                    dist[i - 1][j][1 - x] = next;
                    pq.push({next, i - 1, j, 1 - x});
                }
            }
            if (j + 1 < n) { // right
                long long current = (i + 1) * (j + 2);
                long long next = c + current + (x == 0 ? p[i][j] : 0);
                if (next < dist[i][j + 1][1 - x]) {
                    dist[i][j + 1][1 - x] = next;
                    pq.push({next, i, j + 1, 1 - x});
                }
            }
            if (j - 1 >= 0) { // left
                long long current = (i + 1) * (j);
                long long next = c + current + (x == 1 ? p[i][j] : 0);
                if (next < dist[i][j - 1][1 - x]) {
                    dist[i][j - 1][1 - x] = next;
                    pq.push({next, i, j - 1, 1 - x});
                }
            }
        }
        return -1;
    }
};