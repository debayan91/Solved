class Solution {
public:
    vector<int> largestPower(vector<int>& nums) {
        int n = size(nums);
        vector<int> p(15);
        vector<array<int, 2>> v = {{0, n}}; // range
        for (int i = 0; i < 15; i++) {

            vector<array<int, 2>> u;

            int c = 0;
            bool f = false;

            for (auto [l, r] : v) {

                if (f) {
                    u.push_back({l, r});
                    continue;
                }

                int j = l;

                for (int k = l; k < r; k++) {
                    if ((nums[k] >> (14 - i)) & 1) {
                        swap(nums[j], nums[k]);
                        j++;
                        // insert
                    }
                }

                int ones = j - l, zeroes = r - j;
                c += ones;

                if (ones)
                    u.push_back({l, j});
                if (zeroes) {
                    u.push_back({j, r});
                    f = 1;
                }
            }

            p[i] = c;
            v = move(u);
        }

        return p;
    }
};