class Solution {
public:
    int orangesRotting(vector<vector<int>>& g) {
        queue<vector<int>> q;
        for (int i = 0; i < size(g); i++) {
            for (int j = 0; j < size(g[0]); j++) {
                if (g[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }
        int mins = 0;
        while (!q.empty()) {
            int size = q.size();
            mins++;
            for (int i1 = 0; i1 < size; i1++) {
                int i = q.front()[0];
                int j = q.front()[1];
                q.pop();
                // g[i][j] = 99; // visited
                if (i - 1 >= 0 && (g[i - 1][j] == 1)) {
                    q.push({i - 1, j});
                    g[i - 1][j] = 2;
                }

                if (i + 1 < g.size() && (g[i + 1][j] == 1)) {
                    q.push({i + 1, j});
                    g[i + 1][j] = 2;
                }

                if (j - 1 >= 0 && (g[i][j - 1] == 1)) {
                    q.push({i, j - 1});
                    g[i][j - 1] = 2;
                }

                if (j + 1 < g[0].size() && (g[i][j + 1] == 1)) {
                    q.push({i, j + 1});
                    g[i][j + 1] = 2;
                }
            }
        }
        for (int i = 0; i < size(g); i++) {
            for (int j = 0; j < size(g[0]); j++) {
                if (g[i][j] == 1) {
                    return -1;
                }
            }
        }
        return max(0, mins - 1);
    }
};

// class Solution {
// public:
//     int maxmins = 0;
//     void bfs(vector<vector<int>>& g, int i, int j, int minutes){
//         if(i < 0 || i >= size(g) || j < 0 || j >= size(g[0]) || g[i][j]
//         == 0 || g[i][j] == 25) return; g[i][j] = 25; minutes++; maxmins =
//         minutes > maxmins ? minutes : maxmins; bfs(g, i + 1, j, minutes);
//         bfs(g, i - 1, j, minutes);
//         bfs(g, i, j + 1, minutes);
//         bfs(g, i, j - 1, minutes);
//     }
//     int orangesRotting(vector<vector<int>>& g) {
//         for(int i = 0; i < size(g); i++){
//             for(int j = 0; j < size(g[0]); j++){
//                 if(g[i][j] == 2){
//                     bfs(g, i, j, -1);
//                 }
//             }
//         }
//         return maxmins;
//     }
// };