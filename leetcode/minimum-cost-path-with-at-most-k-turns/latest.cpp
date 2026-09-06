class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = size(grid);
        int n = size(grid[0]);

        if (m == 1 && n == 1)
            return grid.back().back();

        // dist : row -> col -> direction -> k ?

        vector<vector<vector<vector<long long>>>> dist(
            m, vector<vector<vector<long long>>>(
                   n, vector<vector<long long>>(
                          4, vector<long long>(k + 1, INT_MAX))));

        //

        priority_queue <
            tuple<long long, long long, long long, long long, long long>,
            vector<
                tuple<long long, long long, long long, long long, long long>>,
            greater<
                tuple<long long, long long, long long, long long, long long>>>
                pq;

        //

        if (m > 1) { // row 1 // dir 0
            long long cost = grid[0][0] + grid[1][0];
            dist[1][0][0][0] = cost;
            pq.push({cost, 1, 0, 0, 0});
        }

        if (n > 1) { // c 1 // dir 1 of 0123
            long long cost = grid[0][0] + grid[0][1];
            dist[0][1][1][0] = cost;
            pq.push({cost, 0, 1, 1, 0});
        }

        //

        while (!pq.empty()) {
            auto [cost, i, j, last, t] = pq.top();

            pq.pop();

            if (i == m - 1 && j == n - 1)
                return cost;

            if (cost > dist[i][j][last][t])
                continue;

            ////////

            if (i - 1 >= 0) {
                int next = t + (last == 2 ? 0 : 1);

                if (next <= k) {
                    long long nc = cost + grid[i - 1][j];

                    if (nc < dist[i - 1][j][2][next]) {
                        dist[i - 1][j][2][next] = nc;

                        pq.push({nc, i - 1, j, 2, next});
                    }
                }
            }

            ////////

            if (i + 1 < m) {
                int next = t + (last == 0 ? 0 : 1);

                if (next <= k) {
                    long long nc = cost + grid[i + 1][j];

                    if (nc < dist[i + 1][j][2][next]) {
                        dist[i + 1][j][2][next] = nc;

                        pq.push({nc, i + 1, j, 0, next});
                    }
                }
            }

            ////////

            if (j - 1 >= 0) {
                int next = t + (last == 3 ? 0 : 1);

                if (next <= k) {
                    long long nc = cost + grid[i][j - 1];

                    if (nc < dist[i][j - 1][3][next]) {
                        dist[i][j - 1][3][next] = nc;

                        pq.push({nc, i, j - 1, 3, next});
                    }
                }
            }

            ////////

            if (j + 1 < n) {
                int next = t + (last == 1 ? 0 : 1);

                if (next <= k) {
                    long long nc = cost + grid[i][j + 1];

                    if (nc < dist[i][j + 1][1][next]) {
                        dist[i][j + 1][1][next] = nc;

                        pq.push({nc, i, j + 1, 1, next});
                    }
                }
            }
        }
        return -1;
    }
};