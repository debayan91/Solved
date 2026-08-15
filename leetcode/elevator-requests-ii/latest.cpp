using ll = long long;
using ull = unsigned long long;

using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvll = vector<vll>;

using pii = pair<int,int>;
using pll = pair<ll,ll>;

using umap = unordered_map<int,int>;
using uset = unordered_set<int>;
using mp = map<int,int>;

template<class T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<class T>
using maxpq = priority_queue<T>;

#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())

class Solution {
public:
    long long elevatorRequests(int n, int start, vector<int>& r) {
        sort(all(r));
        
        bool need_start = binary_search(all(r), start);

        r.pb(start);

        sort(all(r));

        int m = sz(r);

        int s = lower_bound(all(r), start) - begin(r); // index of start

        vi prefix(m + 1); // fast count req in range
        
        for(int i = 0; i < m; i++){
            int need = r[i] == start ? need_start : 1;
            prefix[i + 1] = prefix[i] + need;
        }

        int total = sz(r) - !need_start;

        vvll dp(m * m, vll(2, -1)); 

        auto dfs = [&](auto&& self, int l, int rr, int side) -> ll{
            ll& res = dp[l * m + rr][side];

            if(res != -1) return res;

            if(l == 0 && rr == m - 1) return res = 0;

            int done = prefix[rr + 1] - prefix[l];
            int rem = total - done;

            res = 4e18;

            int current = side == 0 ? r[l] : r[rr];

            if(l > 0){
                ll dist = abs(current - r[l - 1]);

                res = min(res, dist * rem + self(self, l - 1, rr, 0));
            }

            if(rr + 1 < m){
                ll dist = abs(current - r[rr + 1]);

                res = min(res, dist * rem + self(self, l, rr + 1, 1));
            }

            return res;
        };
        return dfs(dfs, s, s, 0);
    }
};