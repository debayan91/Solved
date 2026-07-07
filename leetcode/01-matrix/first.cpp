class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& g) {
        int m = size(g);
        int n = size(g[0]);
        vector<vector<int>> dist(m, vector<int>(n, 1e5));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(g[i][j] == 0){
                    dist[i][j] = 0;
                } else {
                    int d = 1e5;
                    if(i > 0) d = min(d, dist[i - 1][j]); 
                    if(j > 0) d = min(d, dist[i][j - 1]); 
                    dist[i][j] = d + 1;
                }
            }
        }
        for(int i = m - 1; i >= 0; i--){
            for(int j = n - 1; j >= 0; j--){
                if(g[i][j] == 0){
                    dist[i][j] = 0;
                } else {
                    int d = 1e5;
                    if(i < m - 1) d = min(d, dist[i + 1][j]); 
                    if(j < n - 1) d = min(d, dist[i][j + 1]); 
                    if(i > 0) d = min(d, dist[i - 1][j]); 
                    if(j > 0) d = min(d, dist[i][j - 1]); 
                    dist[i][j] = d + 1;
                }
            }
        }
        return dist;
    }
};