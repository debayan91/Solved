class Solution {
public:
    bool dfs(int node, vector<int>& visited, vector<vector<int>>& list) {
        if (visited[node] == 1) {
            return false;
        }

        if (visited[node] == 2) {
            return true;
        }

        visited[node] = 1;
        for (int next : list[node]) {
            if (!dfs(next, visited, list))
                return false;
        }
        visited[node] = 2;
        return true;
    }
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<vector<int>> list(n);
        for (auto& a : p) {
            list[a[1]].push_back(a[0]);
        }
        vector<int> visited(n, 0);
        for (int i = 0; i < n; i++) {
            if (!dfs(i, visited, list)) {
                return false;
            }
        }
        return true;
    }
};