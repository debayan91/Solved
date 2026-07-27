class Solution {
public:
    int dfs(int current, vector<vector<int>>& adj, vector<int>& res, vector<int>& q){
        if (res[current] != -1)
            return res[current];
        res[current] = current;
        for (int next : adj[current]) {
            int candidate = dfs(next, adj, res, q);
            if (q[candidate] < q[res[current]])
                res[current] = candidate;
        }

        return res[current];
    }
    vector<int> loudAndRich(vector<vector<int>>& a, vector<int>& q) {
        int n = size(q);
        vector<vector<int>> adj(n);
        for(auto& r : a){
            adj[r[1]].push_back(r[0]); // poor -> rich directed graph
        }
        vector<int> res(n, -1);
        for(int i = 0; i < n; i++){
            if(res[i] == -1) dfs(i, adj, res, q);
        }
        return res;
    }
};