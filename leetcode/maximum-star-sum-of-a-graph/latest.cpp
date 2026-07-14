class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = size(vals);
        vector<priority_queue<int, vector<int>, greater<int>>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push(vals[edge[1]]);
            if(adj[edge[0]].size() > k) adj[edge[0]].pop();
            adj[edge[1]].push(vals[edge[0]]);
            if(adj[edge[1]].size() > k) adj[edge[1]].pop();
        }
        int mx = INT_MIN;
        for (int i = 0; i < n; i++) {
            int sum = vals[i];
            while(adj[i].size() != 0){
                if(adj[i].top() > 0) sum += adj[i].top();
                adj[i].pop();
            }
            mx = max(mx, sum);
        }
        return mx;
    }
};