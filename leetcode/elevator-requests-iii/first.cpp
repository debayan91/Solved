using ll = long long;
using ull = unsigned long long;

using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvll = vector<vll>;

using pii = pair<int, int>;
using pll = pair<ll, ll>;

using umap = unordered_map<int, int>;
using uset = unordered_set<int>;
using mp = map<int, int>;

template <class T> using minpq = priority_queue<T, vector<T>, greater<T>>;

template <class T> using maxpq = priority_queue<T>;

#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
class Solution {
public:
    ll mn = LLONG_MAX;

    // unordered_map<ull, ull> dp;
    vector<vector<ll>> dp;

        // void b(int count, int curr, int last, ull time, vector<bool>& vis,
        // vector<vector<int>>& r){
        ll
        b(int mask, int last, int start, vector<vector<int>>& r) {
        int nr = sz(r);

        // if(count == nr){
        //     mn = min(mn, time);
        //     return;
        // } // all done

        // // string state = "";
        // // for(auto a : vis) state += a ? '1' : '0'; // vis as a string

        // ull state = 0;
        // for(bool a : vis) state = 1LL * state * 2 + (a ? 1 : 0);

        // if(last != -1){
        //     ll k = state * 100 + last;

        //     if(dp.count(k) && time >= dp[k]) return;

        //     dp[k] = time;
        // }

        if (dp[mask][last] != -1)
            return dp[mask][last];

        ll res = LLONG_MAX;

        int prev = mask ^ (1 << last);

        if (!prev) {
            ll a = r[last][0], floor = r[last][1], travel = abs(start - floor);

            res = max(travel, a);
        } else {

            for (int i = 0; i < nr; i++) { // for all req
                if (!(prev & (1 << i)))
                    continue;

                // //vis[i] = 1;

                // ll a = r[i][0], t = r[i][1];

                // ll travel = abs(curr - t);

                // ll time_to_reach = travel + time;

                // ll finish = max(time_to_reach, a);

                // b(count + 1, t, i, finish, vis, r);

                // vis[i] = 0;

                ll pt = b(prev, i, start, r);

                ll travel = abs(r[i][1] - r[last][1]);

                ll arr = r[last][0];

                ll fin = max(pt + travel, arr);

                res = min(res, fin);
            }
        }
        return dp[mask][last] = res;
    }
    long long elevatorRequests(int n, int start, vector<vector<int>>& r) {
        int nr = sz(r); if(!nr) return nr;
        mn = LLONG_MAX;
        dp.assign(1 << nr, vector<ll>(nr, -1));
        int full = (1 << nr) - 1;
        
        for(int last = 0; last < nr; last++) mn = min(mn, b(full, last, start, r));
        
        return mn;
    }
};