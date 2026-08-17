class Solution {
public:
    vector<vector<int>> dp;
    vector<int> prefix;

    int solve(int l, int r) {
        if (l == r) return 0;

        if (dp[l][r] != -1) return dp[l][r];

        int res = 0;

        for (int k = l; k < r; k++) { // for every split
            int left = prefix[k + 1] - prefix[l];
            int right = prefix[r + 1] - prefix[k + 1];

            if (left < right) res = max(res, left + solve(l, k));
            else if (left > right) res = max(res, right + solve(k + 1, r));
            else res = max(res, left + max(solve(l, k), solve(k + 1, r)));
        }

        return dp[l][r] = res;
    }

    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        prefix.resize(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }
        dp.assign(n, vector<int>(n, -1));

        return solve(0, n - 1);
    }
};