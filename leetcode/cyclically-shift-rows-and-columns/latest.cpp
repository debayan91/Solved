class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid,
                                    vector<int>& r, vector<int>& c) {
        auto res = grid;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++){
                int jj = (j - (r[i] % n) + n) % n;
                int ii = (i - (c[jj] % n) + n) % n; res[ii][jj] = grid[i][j];
            }
        }
        return res;
    }
};