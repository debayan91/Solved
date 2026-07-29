class Solution {
public:
    vector<long long> d(vector<vector<array<int, 2>>>& adj, int src) {
        int n = size(adj);
        vector<long long> dist(n, LLONG_MAX);
        priority_queue<array<long long, 2>, vector<array<long long, 2>>,
                       greater<array<long long, 2>>>
            pq;
        dist[src] = 0;
        pq.push({0, src});
        while (!pq.empty()) {
            auto [d, i] = pq.top();
            pq.pop();
            if (d > dist[i])
                continue;
            for (auto& [x, y] : adj[i]) {
                if (d + y < dist[x]) {
                    dist[x] = d + y;
                    pq.push({dist[x], x});
                }
            }
        }
        return dist;
    }

    long long minimumWeight(int n, vector<vector<int>>& edges, int src1,
                            int src2, int dest) {
        vector<vector<array<int, 2>>> adj(n);
        vector<vector<array<int, 2>>> rev(n);
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            rev[e[1]].push_back({e[0], e[2]});
        }
        auto a = d(adj, src1);
        auto b = d(adj, src2);
        auto c = d(rev, dest);
        long long mn = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            if (a[i] == LLONG_MAX || b[i] == LLONG_MAX || c[i] == LLONG_MAX)
                continue;
            mn = min(mn, a[i] + b[i] + c[i]);
        }
        return mn == LLONG_MAX ? -1 : mn;
    }
};