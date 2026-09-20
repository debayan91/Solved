using ll = long long;
class Solution {
public:
    long long maxValue(vector<int>& nums) {
        int n = size(nums);
        ll before = 0, current = 0, even = 0, odd = LLONG_MIN, mx = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            ll s = (i % 2) ? -1LL * nums[i] : nums[i];
            before += s;
            current += s;

            if ((i + 1) % 2) {
                if (odd != LLONG_MIN)
                    mx = min(current - odd, mx);
                odd = max(current, odd);
            }

            else {
                mx = min(current - even, mx);

                even = max(current, even);
            }
        }
        ll a = (mx == LLONG_MAX) ? 0LL : max(0LL, -2 * mx);
        return before + a;
    }
};