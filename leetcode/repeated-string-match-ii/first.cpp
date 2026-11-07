class Solution {
public:
    using ll = long long;
    bool repeatedStringMatch(string a, string b, int x, int y) {
        ll an = 1LL * size(a) * x, bn = 1LL * size(b) * y;
        if(bn > an) return 0;
        string s;
        while(size(s) < size(a) + size(b) - 1) s += a;
        auto position = s.find(b);
        if(position == string::npos) return 0;
        ll req = (position + bn + size(a) - 1) / size(a);
        return req <= x;
    }
};