class Solution {
public:
    using ll = long long;
    ll f(int i, auto& a, auto& dp){
        if(i >= size(a)) return 0;
        if(dp[i] > LLONG_MIN) return dp[i];
        ll x = a[i];
        ll res = (x % 3) ? x + f(i + 1, a , dp) : x - f(i + 1, a , dp);
        if(i + 1 < size(a)){
            ll y = a[i] + a[i + 1];
            ll res2 = y % 3 ? y + f(i + 2, a, dp) : y - f(i + 2, a, dp);
            res = max(res2, res);
        }
        return dp[i] = res;
    }
    long long maxDifference(vector<int>& nums) {
        int n = size(nums);
        vector<ll> dp(n, LLONG_MIN);
        return f(0, nums, dp);
    }
};