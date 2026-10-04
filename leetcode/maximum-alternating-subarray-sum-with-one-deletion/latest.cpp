using ll = __int128_t;
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        ll a = nums[0], b, c, d, p, q, m = nums[0], n = size(nums);
        b = c = d = p = q = LLONG_MIN;
        for (int i = 1; i < n; i++) {
            ll v = nums[i];
            ll n_a = max(v, b + v), n_b = a - v, nc = max(d + v, q + v),
               nd = max(c - v, p - v);

            /////

            p = a;
            q = b;

            a = n_a;
            b = n_b;
            c = nc;
            d = nd;
            m = max({a, b, c, d, m});
        }
        return (long long)m;
    }
};