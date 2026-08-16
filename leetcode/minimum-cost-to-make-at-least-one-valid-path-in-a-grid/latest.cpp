using ll = long long;
using ull = unsigned long long;

using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvll = vector<vll>;

using pii = pair<int,int>;
using pll = pair<ll,ll>;

using umap = unordered_map<int,int>;
using uset = unordered_set<int>;
using mp = map<int,int>;

template<class T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<class T>
using maxpq = priority_queue<T>;

#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = sz(grid);
        int n = sz(grid[0]);

        vvi dist(m, vi(n, INT_MAX));

        minpq<array<int, 3>> pq; // cost i j

        dist[0][0] = 0;
        pq.push({0, 0, 0});

        vi dr = {0, 0, 1, -1};
        vi dc = {1, -1, 0, 0};

        while (!pq.empty()) {
            auto [cost, r, c] = pq.top();
            pq.pop();

            if (cost != dist[r][c]) continue;

            if (r == m - 1 && c == n - 1) return cost;

            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;

                int dir = d + 1;
                int cc = cost + (grid[r][c] != dir);

                if (cc < dist[nr][nc]) {
                    dist[nr][nc] = cc;
                    pq.push({cc, nr, nc});
                }
            }
        }
        return -1;
    }
};