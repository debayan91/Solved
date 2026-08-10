class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<int> dp(n + 1, -1);

        vector<int> squares;
        for (int i = 1; i * i <= n; i++) {
            squares.push_back(i * i);
        }

        auto solve = [&](auto&& self, int rem) -> bool {
            if (rem == 0)
                return false;

            if (dp[rem] != -1)
                return dp[rem];

            for (int sq : squares) {
                if (sq > rem)
                    break;

                if (!self(self, rem - sq))
                    return dp[rem] = true;
            }

            return dp[rem] = false;
        };

        return solve(solve, n);
    }
};