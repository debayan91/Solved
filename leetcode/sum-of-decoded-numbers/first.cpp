#pragma region
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

using pii = pair<int, int>;
using pll = pair<ll, ll>;

using vi = vector<int>;
using vll = vector<ll>;
using vpi = vector<pii>;
using vpll = vector<pll>;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

#define pb push_back
#define eb emplace_back
#define fi first
#define se second

const int INF = 1e9;
const ll LINF = 4e18;
const int MOD = 1e9 + 7;

template <typename T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}
template <typename T>
bool chmax(T &a, const T &b) {
    if (b > a) {
        a = b;
        return true;
    }
    return false;
}
const int MAX = 200005;
ll fact[MAX];
ll invFact[MAX];
ll power(ll base, ll exp) {
    ll res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1)
            res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}
ll modinv(ll n) {
    return power(n, MOD - 2);
}
void precomp_ncr() {
    fact[0] = 1;
    invFact[0] = 1;
    for (int i = 1; i < MAX; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    invFact[MAX - 1] = modinv(fact[MAX - 1]);
    for (int i = MAX - 2; i >= 1; i--) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
}
ll nCr(ll n, ll r) {
    if (r < 0 || r > n)
        return 0;
    ll num = fact[n];
    ll den = (invFact[r] * invFact[n - r]) % MOD;
    return (num * den) % MOD;
}
ll gcdll(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}
ll lcmll(ll a, ll b) {
    return a / gcdll(a, b) * b;
}
ll modpow(ll a, ll b, ll mod = MOD) {
    ll res = 1;
    while (b) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
bool prime(int x) {
    if (x < 2)
        return 0;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0)
            return 0;
    }
    return 1;
}
// const ll MOD = 998244353;
struct InputReader {
    template <typename T>
    operator T() {
        T val;
        cin >> val;
        return val;
    }
};

InputReader input() { return InputReader{}; }

template <typename... Args>
void read(Args &...args) {
    (cin >> ... >> args);
}

template <typename T>
vector<T> read_vec(int n) {
    vector<T> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    return v;
}

template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
    return os << p.first << " " << p.second;
}

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    for (size_t i = 0; i < v.size(); i++) {
        os << (i ? " " : "") << v[i];
    }
    return os;
}

template <typename... Args>
void output(const Args &...args) {
    bool first = true;
    ((cout << (first ? "" : " ") << args, first = false), ...);
    cout << "\n";
}

class Solution {
public:
    int sumDecoded(vector<long long>& nums) {
        ll sum = 0;
        for(ll a : nums){
            ll w = a % 10, d = a / 10;
            ll dd = size(to_string(d));
            ll p = 1; for(int i = 0; i < dd - w; i++) p *= 10;
            ll x = d / p, y = d % p;
            sum = (sum + modpow(x, y)) % MOD;
        }
        return sum;
    }
};