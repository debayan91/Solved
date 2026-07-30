class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        int n = cost.size();
        vector<int> ans(n);

        int mn = INT_MAX;
        for (int i = 0; i < n; i++) {
            mn = min(mn, cost[i]);
            ans[i] = mn;
        }

        return ans;
    }
};