class Solution {
public:
    bool flag = false;
    void func(vector<vector<int>>& grid, int health, int i, int j) {
        if (i < 0 || i >= size(grid) || j < 0 || j >= size(grid[0]) || flag) {
            return;
        }
        if (i == size(grid) - 1 && j == size(grid[0]) - 1) {
            if (grid[i][j] == 1) {
                if (health - 1 >= 1) {
                    flag = true;
                    return;
                } else
                    return;
            } else if (grid[i][j] == 0) {
                flag = true;
                return;
            }
        }
        // 0 or 1 -> unvisited
        // when visited -> health + 10
        if (grid[i][j] == 0) {
            grid[i][j] = health;

            // mark as visited
            grid[i][j] += 10;

            func(grid, health, i, j + 1);
            func(grid, health, i + 1, j);
            func(grid, health, i, j - 1);
            func(grid, health, i - 1, j);
        } else if (grid[i][j] == 1) {
            if (health - 1 < 1)
                return;
            grid[i][j] = --health;

            // mark as visited
            grid[i][j] += 100000;

            func(grid, health, i, j + 1);
            func(grid, health, i + 1, j);
            func(grid, health, i, j - 1);
            func(grid, health, i - 1, j);
        } else {
            if (grid[i][j] < 100000 - 100) {
                // it was 0 before
                int health_here = grid[i][j] - 10;
                if (health <= health_here)
                    return;

                grid[i][j] = health + 10;

                func(grid, health, i, j + 1);
                func(grid, health, i + 1, j);
                func(grid, health, i, j - 1);
                func(grid, health, i - 1, j);
            } else {
                // it was 1 before
                int health_here = grid[i][j] - 100000;
                if (--health <= health_here)
                    return;

                grid[i][j] = health + 100000;

                func(grid, health, i, j + 1);
                func(grid, health, i + 1, j);
                func(grid, health, i, j - 1);
                func(grid, health, i - 1, j);
            }
        }
    }
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        func(grid, health, 0, 0);
        bool t = flag;
        flag = false;
        return t;
    }
};