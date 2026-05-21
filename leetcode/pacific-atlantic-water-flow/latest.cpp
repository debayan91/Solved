class Solution {
public:
    bool pacific, atlantic;
    void dfs(vector<vector<int>>& grid, int i, int j, int m, int n, vector<vector<int>>& visited){
        if(i < 0 || i >= m || j < 0 || j >= n) return;
        if(visited[i][j] > 0) return;
        if(pacific && atlantic) return;
        if(i == 0 || j == 0){
            pacific = true;
        }
        if(i == m - 1 || j == n - 1){
            atlantic = true;
        }
        if(pacific && atlantic) return;
        int value = grid[i][j];
        visited[i][j] = 1;

        if(i + 1 < m && grid[i + 1][j] <= value) dfs(grid, i + 1, j, m, n, visited);
        if(i - 1 >= 0 && grid[i - 1][j] <= value) dfs(grid, i - 1, j, m, n, visited);
        if(j + 1 < n && grid[i][j + 1] <= value) dfs(grid, i, j + 1, m, n, visited);
        if(j - 1 >= 0  && grid[i][j - 1] <= value) dfs(grid, i, j - 1, m, n, visited);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& grid) {
        vector<vector<int>> res;
        
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        //int visited[m][n] = {0};
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                pacific = atlantic = false;
                //visited = {0};
                
                visited.assign(m, vector<int>(n, 0));
                dfs(grid, i, j, m, n, visited);
                if(pacific && atlantic) res.push_back({i, j});
            }
        }
        return res;
    }
};