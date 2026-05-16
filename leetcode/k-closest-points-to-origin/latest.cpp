#pragma GCC optimize("Ofast,unroll-loops,fast-math")
#pragma GCC target("avx,avx2,fma,sse4,popcnt,lzcnt,bmi,bmi2")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

static constexpr size_t mxal = alignof(max_align_t);
alignas(mxal) static unsigned char buf[256 * 1024 * 1024];
static size_t pos = 0;

void* operator new(size_t sz) {
    size_t pad = (mxal - (pos % mxal)) % mxal;
    pos += pad + sz;
    return (void*)(&buf[pos - sz]);
}

void* operator new[](size_t sz) {
    return operator new(sz);
}

void operator delete(void*) noexcept {}
void operator delete[](void*) noexcept {}
void operator delete(void*, size_t) noexcept {}
void operator delete[](void*, size_t) noexcept {}

struct chash {
    static ull splitmix64(ull x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(ull x) const {
        static const ull rnd =
            chrono::steady_clock::now().time_since_epoch().count();

        return splitmix64(x + rnd);
    }
};

template <class K, class V>
using umap = unordered_map<K, V, chash>;

template <class T>
using uset = unordered_set<T, chash>;

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();


class Solution {
public:
    class point {
    public:
        int x, y, dist;
        point(int x, int y) {
            this->x = x;
            this->y = y;
            this->dist = (x * x + y * y);
        }
    };

    class cmp {
    public:
        bool operator()(point* a, point* b) { return a->dist < b->dist; }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        priority_queue<point*, vector<point*>, cmp> pq;
        for(auto a : points){
            point* c = new point(a[0], a[1]);
            pq.push(c);
            if(pq.size() > k) pq.pop();
        }
        while(pq.size() != 0){
            point* p = pq.top();
            pq.pop();
            res.push_back({p->x, p->y});
        }
        return res;
    }
};