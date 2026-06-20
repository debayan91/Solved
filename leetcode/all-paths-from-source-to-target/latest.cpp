class Solution {
public:
    void dfs(vector<vector<int>>& res, vector<vector<int>>& graph, vector<int>& current, int i){
        if(i == graph.size() - 1){
            res.push_back(current);
            return;
        }
        for(int j : graph[i]){
            current.push_back(j);
            dfs(res, graph, current, j);
            current.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> current = {0};
        for(int i : graph[0]){
            current.push_back(i);
            dfs(res, graph, current, i);
            current.pop_back();
        }
        return res;
    }
};