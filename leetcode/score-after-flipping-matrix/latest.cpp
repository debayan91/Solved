class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int sum = 0;
        int two = 1;
        // exclude 1st column - all ones always
        for (int j = grid[0].size() - 1; j > 0; j--) {
            // iterate columnwise
            int c0 = 0;
            int c1 = 0;
            for (int i = 0; i < grid.size(); i++) {
                if (grid[i][j]) {
                    // 1
                    if (grid[i][0]) {
                        c1++;
                    } else {
                        c0++;
                    }
                } else {
                    // 0
                    if (!grid[i][0]) {
                        c1++;
                    } else {
                        c0++;
                    }
                }
            }
            sum += max(c1, c0) * two;
            two += two;
        }
        sum += grid.size() * two;
        return sum;
    }
};