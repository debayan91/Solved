class Solution {
public:
    int minLights(vector<int>& lights) {
        int n = size(lights);
        vector<int> m(n, 0);
        for (int i = 0; i < n; i++) {
            if (lights[i] != 0) {

                int v = lights[i];
                int start = max(0, i - v);
                int end = min(n - 1, i + v);

                int size = end - start + 1;

                // amrk all

                m[start] = max(size, m[start]);
            }
        }
        vector<int> c(n, 0);
        int r = -1;
        for (int i = 0; i < n; i++) {
            if (m[i]) {
                r = max(r, i + m[i] - 1);
            }

            if (i <= r) {
                c[i] = 1;
            }
        }
        int more = 0;
        int i = 0;
        while (i < n) {
            if (c[i]) {
                i++;
                continue;
            }
            more++;
            c[i] = 1;

            if (i + 1 < n)
                c[i + 1] = 1;
            if (i + 2 < n)
                c[i + 2] = 1;

            i += 3;
        }

        return more;
    }
};