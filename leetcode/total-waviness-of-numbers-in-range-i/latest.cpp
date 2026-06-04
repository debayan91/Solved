// class Solution {
// public:
//     int totalWaviness(int num1, int num2) {
        
//     }
// };
class Solution {
public:
    struct Node {
        long long cnt, wav;
    };

    string s;
    Node dp[20][2][11][11][20];
    bool vis[20][2][11][11][20];

    Node dfs(int pos, bool tight, int p1, int p2, int len) {
        if (pos == s.size()) return {1, 0};

        if (vis[pos][tight][p1][p2][len])
            return dp[pos][tight][p1][p2][len];

        vis[pos][tight][p1][p2][len] = true;

        int lim = tight ? s[pos] - '0' : 9;
        Node res = {0, 0};

        for (int d = 0; d <= lim; d++) {
            bool nt = tight && (d == lim);

            if (len == 0 && d == 0) {
                Node cur = dfs(pos + 1, nt, 10, 10, 0);
                res.cnt += cur.cnt;
                res.wav += cur.wav;
            } else {
                long long add = 0;

                if (len >= 2) {
                    if ((p1 > p2 && p1 > d) || (p1 < p2 && p1 < d))
                        add = 1;
                }

                Node cur = dfs(pos + 1, nt, d, p1, len + 1);

                res.cnt += cur.cnt;
                res.wav += cur.wav + add * cur.cnt;
            }
        }

        return dp[pos][tight][p1][p2][len] = res;
    }

    long long solve(long long x) {
        if (x < 0) return 0;
        s = to_string(x);
        memset(vis, 0, sizeof(vis));
        return dfs(0, 1, 10, 10, 0).wav;
    }

    int totalWaviness(int num1, int num2) {
        return solve(num2) - solve(num1 - 1);
    }
};