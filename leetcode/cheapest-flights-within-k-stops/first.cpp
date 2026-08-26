class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto a : flights) adj[a[0]].push_back({a[2], a[1]});
        vector<vector<int>> dist(n, vector<int>(k + 3, INT_MAX));
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;        
        // dist, node, stops
        pq.push({0, src, 0});
        dist[src][0] = 0;
        while(!pq.empty()){
            auto [dis, node, stops] = pq.top();
            pq.pop();
            if (node == dst) return dis;
            if(stops > k || dis > dist[node][stops]) continue;
            for(auto& [cost, next] : adj[node]){
                if(dis + cost < dist[next][stops + 1]){
                    dist[next][stops + 1] = dis + cost;
                    pq.push({dist[next][stops + 1], next, stops + 1});
                }
            }
        }
        return -1;
    }
};