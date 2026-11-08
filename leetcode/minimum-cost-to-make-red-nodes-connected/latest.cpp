class Solution {
public:
    using ll = long long;
    long long minCost(int n, string colors, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }    
        ll b = 0, res = 0;
        function<pair<ll, ll>(int, int)> f = [&](int u, int p) -> pair<ll, ll> {
            ll ss = 1, sum = 0;
            for(int v : adj[u]){
                if(v == p) continue;
                auto [s, d] = f(v, u);
                ss += s;
                sum += min(0LL, d);
            }
            if(colors[u] == 'R') b += ss;
            ll dp = sum + (colors[u] == 'R' ? -ss : ss);
            res = min(dp, res);
            return {ss, dp};
        };
        f(0, -1);
        return b + res;
    }
};