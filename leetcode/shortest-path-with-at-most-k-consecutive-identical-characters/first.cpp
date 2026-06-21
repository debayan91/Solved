class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        // djik
        vector<vector<pair<int, int>>> list(n);
        for (auto e : edges) {
            list[e[0]].push_back({e[1], e[2]});
        }
        // for every node -> k possibilities ?
        // dist to every single possibility -> n*k
        vector<vector<int>> dist(n, vector<int>(k + 1, INT_MAX));

        dist[0][1] = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            pq;
        pq.push({0, 0, 1});
        while (!pq.empty()) {
            auto current = pq.top();
            pq.pop();
            int cw = current[0];
            int u = current[1];
            int chars = current[2];
            if (cw != dist[u][chars]) {

            } else {
                for (auto [v, w] : list[u]) {
                    int len;
                    if (labels[u] == labels[v]) {
                        len = chars + 1;
                        if (len > k)
                            continue;
                    } else {
                        len = 1;
                    }
                    int nw = w + cw;
                    if (nw < dist[v][len]) {
                        dist[v][len] = nw;
                        pq.push({nw, v, len});
                    }
                }
            }
        }
        int res = INT_MAX;
        for (int i = 1; i <= k; i++) {
            res = min(res, dist[n - 1][i]);
        }
        if (res == INT_MAX)
            return -1;
        return res;
    }
};