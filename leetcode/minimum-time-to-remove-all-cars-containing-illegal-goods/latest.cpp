class Solution {
public:
    int minimumTime(string s) {
        int n = s.size();
        vector<int> dp(n);

        // dp[i] = minimum cost to remove all 1s in s[0...i]

        dp[0] = (s[0] == '1') ? 1 : 0; // first

        for (int i = 1; i < n; i++) {
            if (s[i] == '0') { // carry along
                dp[i] = dp[i - 1];
            } else {
                dp[i] = min(
                    dp[i - 1] + 2, // +2
                    i + 1 // the cost of literally removing everything before it
                );
            }
        }

        int res = dp[n - 1];

        // Remove the remaining suffix from the right
        for (int i = 0; i < n; i++) {
            res = min(res, dp[i] + (n - 1 - i));
        }

        return res;
    }
};