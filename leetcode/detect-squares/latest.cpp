class DetectSquares {
public:
    unordered_map<int, unordered_map<int, int>> points;

    DetectSquares() {}

    void add(vector<int> point) {
        points[point[0]][point[1]]++;
    }

    int count(vector<int> point) {
        int x = point[0];
        int y = point[1];
        int ans = 0;

        for (auto &[ny, cnt] : points[x]) {
            if (ny == y) continue;

            int d = ny - y;

            ans += cnt * points[x + d][y] * points[x + d][ny];
            ans += cnt * points[x - d][y] * points[x - d][ny];
        }

        return ans;
    }
};