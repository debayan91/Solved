class Solution {
public:
    int minTimeToReach(vector<vector<int>>& g) {
        int m = g.size();
        int n = g[0].size();
        
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = 0;
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, 0});
        
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        
        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            
            int time = curr[0];
            int i = curr[1];
            int j = curr[2];
            
            if (i == m - 1 && j == n - 1) {
                return time;
            }
            
            if (time > dist[i][j]) continue;
            
            for (int k = 0; k < 4; k++) {
                int ni = i + dr[k];
                int nj = j + dc[k];
                
                if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                    int next_time = max(time, g[ni][nj]) + 1;
                    
                    if (next_time < dist[ni][nj]) {
                        dist[ni][nj] = next_time;
                        pq.push({next_time, ni, nj});
                    }
                }
            }
        }
        
        return -1;
    }
};