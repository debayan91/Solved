class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = size(seats);
        int prev = -1;
        int mx = 0;

        for (int i = 0; i < n; i++) {
            if (seats[i] == 1) {
                if (prev == -1)
                    mx = i; // leading gap
                else
                    mx = max(mx, (i - prev) / 2); // middle gap
                prev = i;
            }
        }

        return max(mx, n - 1 - prev); // trailing gap
    }
};