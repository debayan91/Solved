class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();

        if (n <= 2)
            return n;

        int res = 0;

        for (int i = 0; i < n; i++) {

            map<pair<int, int>, int> mp; /// slope,f

            for (int j = i + 1; j < n; j++) {

                int dy = points[j][1] - points[i][1];
                int dx = points[j][0] - points[i][0];
                int g = gcd(abs(dy), abs(dx));
                dy /= g;
                dx /= g;

                if (dx < 0) {
                    dx = -dx;           
                    dy = -dy;
                }

                if (dx == 0)
                    dy = 1;

                if (dy == 0)
                    dx = 1;

                mp[{dy, dx}]++;

                res = max(res, mp[{dy, dx}] + 1);
            }
        }

        return res;
    }
};