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

void* operator new[](size_t sz) { return operator new(sz); }

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

template <class K, class V> using umap = unordered_map<K, V, chash>;

template <class T> using uset = unordered_set<T, chash>;

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int divide(int c, int d) {
        // edge case
        if (c == INT_MIN && d == -1)
            return INT_MAX;
        if (c == INT_MAX && d == -1)
            return INT_MIN + 1;

        int sign = 0;
        if (c > 0 && d < 0 || c < 0 && d > 0)
            sign = 1;
        long long a = abs((long long)c);
        long long b = abs((long long)d);
        long long q = 0;

        while (a > 0 && a >= b) {
            a = a - b;
            q++;
        }
        if (sign) {
            long long a = 0 - q;
            q = a;
        }

        if (q > INT_MAX)
            q = INT_MAX;
        if (q < INT_MIN)
            q = INT_MIN;

        return q;
    }
};