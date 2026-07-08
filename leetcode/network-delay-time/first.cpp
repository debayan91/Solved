class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        for(int j = 0; j < n - 1; j++){
            for(auto& edge : times){
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];
                if(dist[u] != INT_MAX && dist[u] + w < dist[v]){
                    dist[v] = dist[u] + w;
                }
            }
        }
        int a = *max_element(begin(dist) + 1, end(dist));
        return a == INT_MAX ? -1 : a;
    }
};