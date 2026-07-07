class Solution {
public:
    void dfs(vector<vector<int>>& g, vector<bool>& visited, int node){
        for(int i = 0; i < g[node].size(); i++){
            if(g[node][i] == 0 || visited[i]) continue;
            visited[i] = true;
            dfs(g, visited, i);
        }
    }
    int findCircleNum(vector<vector<int>>& g) {
        int m = size(g);
        vector<bool> visited(m, false);
        int count = 0;
        for(int i = 0; i < m; i++){
            if(visited[i]) continue;
            visited[i] = true;
            count++;
            dfs(g, visited, i);
        }
        return count;
    }
};