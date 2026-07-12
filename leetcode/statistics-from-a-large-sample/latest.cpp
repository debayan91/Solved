class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        long double mn = 257, mx = -1, mean = 0, median = -1, mode = -1;
        int k = 0;
        for (int i = 0; i < 256; i++) {
            mean += 1LL * count[i] * i;
            if (count[i]) {
                k += count[i];
                mn = min(mn, (long double)i);
                mx = max(mx, (long double)i);
                if (count[i] > median) {
                    median = count[i];
                    mode = i;
                }
            }
        }
        int sum = 0;
        int m = k / 2;
        median = 0;
        for (int i = 0; i < 256; i++) {
            sum += count[i];
            if (sum > m) {
                median = i;
                break;
            }
            if (sum == m) {
                if (k % 2 == 1) {
                    // Odd number of elements: middle element is the next one
                    i++;
                    while (i < 256 && count[i] == 0)
                        i++;
                    median = i;
                } else {
                    // Even number of elements: average current and next
                    median = i;
                    i++;
                    while (i < 256 && count[i] == 0)
                        i++;
                    median = (median + i) / 2.0;
                }
                break;
            }
        }
        mean /= k;
        return {(double)mn, (double)mx, (double)mean, (double)median, (double)mode};
    }
};