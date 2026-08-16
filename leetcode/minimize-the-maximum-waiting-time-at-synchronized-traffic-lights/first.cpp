using ll = long long;

using vi = vector<int>;
using vll = vector<ll>;

using pii = pair<int,int>;
using pll = pair<ll,ll>;

using umap = unordered_map<int,int>;
using uset = unordered_set<int>;

using mp = map<int,int>;

using pq = priority_queue<int>;
using minpq = priority_queue<int, vector<int>, greater<int>>;

#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
class Solution {
public:
    int minPenalty(int p, vector<int>& l, vector<int>& a) {
        int n = size(l), an = size(a);

        int mxw = *max_element(all(l));

        vi r;
        for(int x : a) r.pb(x % p);
        sort(all(r));

        auto f = [&](int w) -> bool {
          int t = p - w;
            auto it = lower_bound(begin(r), end(r), t);
            if(it == begin(r)) return 1;
            return mxw > *(it - 1);
        };

        int ll = 0, rr = p - 1, res = p - 1;
        while(ll <= rr){
            int m = ll + (rr - ll) / 2;
            if(f(m)){
                res = m;
                rr = m - 1;
            } else ll = m + 1;
        }
        return res;
    }
};