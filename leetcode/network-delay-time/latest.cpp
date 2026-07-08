class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<array<int, 2>>> adj(n + 1);
        for (const auto& edge : times) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        priority_queue<array<int, 2>, vector<array<int, 2>>, greater<>> pq;
        pq.push({0, k});
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if(d > dist[u]) continue;
            for (const auto& [v, w] : adj[u]) {
                if(dist[v] > d + w){
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }
        int a = *max_element(begin(dist) + 1, end(dist));
        return a == INT_MAX ? -1 : a;
    }
};