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
pll fib(ll n) {
    if (!n)
        return {0, 1};
    auto [a, b] = fib(n >> 1);
    ll c = (a * ((2 * b - a + MOD) % MOD)) % MOD;
    ll d = (a * a % MOD + b * b % MOD) % MOD;
    return (n & 1) ? pll{d, (c + d) % MOD} : pll{c, d};
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

///

void sort2d(vector<vector<int>> &a) {
    int rows = a.size();

    auto total = [&]() {
        int n = 0;
        for (auto &row : a)
            n += row.size();
        return n;
    };

    int n = total();

    auto get = [&](int idx) -> int & {
        for (auto &row : a) {
            if (idx < (int)row.size())
                return row[idx];

            idx -= row.size();
        }

        throw out_of_range("index");
    };

    auto siftDown = [&](int start, int size) {
        int root = start;

        while (2 * root + 1 < size) {
            int child = 2 * root + 1;

            if (child + 1 < size && get(child) < get(child + 1))
                child++;

            if (get(root) >= get(child))
                break;

            swap(get(root), get(child));
            root = child;
        }
    };

    for (int i = n / 2 - 1; i >= 0; --i)
        siftDown(i, n);

    for (int i = n - 1; i > 0; --i) {
        swap(get(0), get(i));
        siftDown(0, i);
    }
}

vector<bool> sieve(int n) {
    vector<bool> isPrime(n + 1, true);

    if (n >= 0)
        isPrime[0] = false;
    if (n >= 1)
        isPrime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
        }
    }

    return isPrime;
}

ll floor_(ll a, ll b) {
    ll q = a / b;
    ll r = a % b;

    if (r != 0 && ((r > 0) != (b > 0)))
        --q;

    return q;
}

ll ceil_(ll a, ll b) {
    ll q = a / b;
    ll r = a % b;

    if (r != 0 && ((r > 0) == (b > 0)))
        ++q;

    return q;
}

vector<pair<ll, int>> factorize(ll n) {
    vector<pair<ll, int>> res;

    for (ll p = 2; p <= n / p; ++p) {
        if (n % p == 0) {
            int cnt = 0;

            while (n % p == 0) {
                n /= p;
                ++cnt;
            }

            res.eb(p, cnt);
        }
    }

    if (n > 1)
        res.eb(n, 1);

    return res;
}

vector<ll> divisors(ll n) {
    vector<ll> res;

    for (ll i = 1; i <= n / i; i++) {
        if (n % i == 0) {
            res.pb(i);

            if (i != n / i)
                res.pb(n / i);
        }
    }

    return res;
}

template <int N>
struct Mat {
    array<array<ll, N>, N> a{};

    static Mat id() {
        Mat res;
        for (int i = 0; i < N; i++)
            res.a[i][i] = 1;
        return res;
    }

    Mat operator*(const Mat &o) const {
        Mat res;
        for (int i = 0; i < N; i++)
            for (int k = 0; k < N; ++k)
                if (a[i][k])
                    for (int j = 0; j < N; ++j)
                        res.a[i][j] = (res.a[i][j] + a[i][k] * o.a[k][j]) % MOD;
        return res;
    }

    Mat pow(ll p) const {
        Mat base = *this, res = Mat::id();
        for (; p > 0; p >>= 1, base = base * base)
            if (p & 1)
                res = res * base;
        return res;
    }
};

template <typename T>
vector<T> prefix_sum(const vector<T> &a) {
    vector<T> pref(a.size() + 1);

    for (int i = 0; i < sz(a); i++)
        pref[i + 1] = pref[i] + a[i];

    return pref;
}

// void solve();

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     // precomp_ncr();

//     int T = 1;
//     cin >> T;

//     while (T--) {
//         solve();
//     }

//     return 0;
// }

struct SegTree {
    int n;
    vector<ll> t;

    SegTree(int n) : n(n), t(2 * n) {}

    void setval(int p, ll v) {
        for (t[p += n] = v; p > 1; p >>= 1)
            t[p >> 1] = t[p] + t[p ^ 1];
    }

    ll query(int l, int r) { // [l,r)
        ll res = 0;

        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1)
                res += t[l++];
            if (r & 1)
                res += t[--r];
        }

        return res;
    }
};

struct BIT {
    int n;
    vector<ll> bit;

    BIT(int n) : n(n), bit(n + 1) {}

    void add(int i, ll x) {
        for (i++; i <= n; i += i & -i)
            bit[i] += x;
    }

    ll sumPrefix(int i) {
        ll res = 0;
        for (i++; i > 0; i -= i & -i)
            res += bit[i];
        return res;
    }

    ll sum(int l, int r) {
        if (l > r)
            return 0;
        return sumPrefix(r) - (l ? sumPrefix(l - 1) : 0);
    }
};

vector<int> compress(vector<int> a) {
    vector<int> b = a;
    sort(all(b));
    b.erase(unique(all(b)), b.end());

    for (int &x : a)
        x = lower_bound(all(b), x) - b.begin();

    return a;
}

// (a / b) mod MOD
ll divmod(ll a, ll b) {
    return a % MOD * modinv(b) % MOD;
}

// 1 + x + ... + x^(n-1)
ll geom(ll x, ll n) {
    if (n == 0)
        return 0;
    if (x == 1)
        return n % MOD;
    return (modpow(x, n) - 1 + MOD) % MOD * modinv(x - 1) % MOD;
}

vector<int> topo(const vector<vector<int>> &g) {
    int n = g.size();
    vector<int> indeg(n);

    for (auto &adj : g)
        for (int v : adj)
            indeg[v]++;

    queue<int> q;
    for (int i = 0; i < n; i++)
        if (!indeg[i])
            q.push(i);

    vector<int> res;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        res.pb(u);

        for (int v : g[u])
            if (--indeg[v] == 0)
                q.push(v);
    }

    return res;
}

vector<int> zero_one_bfs(int s, const vector<vector<pii>> &g) {
    int n = g.size();
    vector<int> d(n, INF);
    deque<int> q;

    d[s] = 0;
    q.push_front(s);

    while (!q.empty()) {
        int u = q.front();
        q.pop_front();

        for (auto [v, w] : g[u]) {
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                if (w == 0)
                    q.push_front(v);
                else
                    q.push_back(v);
            }
        }
    }
    return d;
}

vector<int> bfs(int s, const vector<vector<int>> &g) {
    int n = g.size();
    vector<int> d(n, -1);
    queue<int> q;

    d[s] = 0;
    q.push(s);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : g[u]) {
            if (d[v] == -1) {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
    return d;
}

using pli = pair<ll, int>;

vector<ll> dijkstra(int s, const vector<vector<pli>> &g) {
    int n = g.size();
    vector<ll> d(n, LINF);
    priority_queue<pli, vector<pli>, greater<pli>> pq;

    d[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        auto [du, u] = pq.top();
        pq.pop();

        if (du != d[u])
            continue;

        for (auto [v, w] : g[u]) {
            if (d[v] > du + w) {
                d[v] = du + w;
                pq.push({d[v], v});
            }
        }
    }
    return d;
}

// struct DSU {
//     vector<int> p, sz;

//     DSU(int n) : p(n), sz(n, 1) {
//         iota(all(p), 0);
//     }

//     int find(int x) {
//         return p[x] == x ? x : p[x] = find(p[x]);
//     }

//     bool unite(int a, int b) {
//         a = find(a);
//         b = find(b);
//         if (a == b) return false;

//         if (sz[a] < sz[b]) swap(a, b);
//         p[b] = a;
//         sz[a] += sz[b];
//         return true;
//     }

//     bool same(int a, int b) {
//         return find(a) == find(b);
//     }
// };

ll first_true(ll lo, ll hi, auto pred) {
    while (lo < hi) {
        ll mid = lo + (hi - lo) / 2;
        if (pred(mid))
            hi = mid;
        else
            lo = mid + 1;
    }
    return lo;
}

ll last_true(ll lo, ll hi, auto pred) {
    while (lo < hi) {
        ll mid = lo + (hi - lo + 1) / 2;
        if (pred(mid))
            lo = mid;
        else
            hi = mid - 1;
    }
    return lo;
}

#pragma endregion
class Solution {
public:
    long long minimumMaxValue(int n, int i, int v) {
        if(n == 1) return v;
        if(v == 1) return -1;

        ll p = factorize(v)[0].first;
        if(i && v < p + 2 * i) return -1;

        int right = n - 1 - i;

        if(!right) return v;

        ll res = p + 2 * (right - 1);
        return v + res;
    }
};