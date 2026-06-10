class Solution {
public:
    void dfs(vector<vector<int>>& g, int i, int j) {
        if(i < 0 || i >= size(g) || j < 0 || j >= size(g[0]) || g[i][j] == 0) return;
        g[i][j] = 0;
        dfs(g, i - 1, j);
        dfs(g, i + 1, j);
        dfs(g, i, j + 1);
        dfs(g, i, j - 1);
    }
    int numEnclaves(vector<vector<int>>& g) {
        int count = 0;
        for(int i = 0; i < size(g); i++){
            if(g[i][0]) dfs(g, i, 0);
        }
        for(int i = 0; i < size(g); i++){
            if(g[i][size(g[0]) - 1]) dfs(g, i, size(g[0]) - 1);
        }
        for(int j = 0; j < size(g[0]); j++){
            if(g[size(g) - 1][j]) dfs(g, size(g) - 1, j);
        }
        for(int j = 0; j < size(g[0]); j++){
            if(g[0][j]) dfs(g, 0, j);
        }
        for(auto a : g){
            for(auto b : a){
                if(b) count++;
            }
        }
        return count;
    }
};