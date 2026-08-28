class Solution {
public:
    int findComplement(int x) {
        return x == 0 ? 1 : (-x - 1) & ((1LL << (32 - __builtin_clz(x))) - 1);
    }
};