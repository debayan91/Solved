class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        long long mod = 1e9 + 7;
        vector<vector<pair<long long, long long>>> adj(n);
        for(const auto& road : roads){
            // bidirectional
            adj[road[0]].push_back({road[2], road[1]});
            adj[road[1]].push_back({road[2], road[0]});
        }
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<>> pq;
        vector<long long> dist(n, LLONG_MAX);
        dist[0] = 0;
        pq.push({0, 0}); // dist, node
        long long count = 0;
        vector<long long> ways(n, 0);
        ways[0] = 1;
        while(!pq.empty()){
            auto [d, u] = pq.top();
            pq.pop();
            if(d > dist[u]) continue; // stale
            for(const auto& [w, v] : adj[u]){
                if(d + w < dist[v]){
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                    ways[v] = ways[u];  
                } else if (d + w == dist[v]){
                    ways[v] = (ways[v] + ways[u]) % mod;
                }
            }
        }
        return ways[n - 1];
    }
};