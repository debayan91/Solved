class Solution {
public:
    int f(int u, auto& g, auto& o, auto& s){
        if(size(g[u]) == 0) return s[u];
        int t = 0, m = INT_MAX; for(int v : g[u]){
            int x = f(v, g, o , s);
            t += x; m = min(m, x);
        }
        if(o[u] == 0){if(m < 0) t -= m;} else t -=m; 
        return s[u] + t;
    }
    int maxScore(vector<int>& p, vector<int>& op, vector<int>& sc) {
        int n = size(op);
        vector<vector<int>> adj(n); for(int i = 1; i < n; i++) adj[p[i]].push_back(i);
        return f(0, adj, op, sc);
    }
};