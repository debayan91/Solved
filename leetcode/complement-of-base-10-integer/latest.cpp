class Solution {
public:
    int bitwiseComplement(int x) {
        return x == 0 ? 1 : (-x - 1) & ((1 << (32 - __builtin_clz(x))) - 1);
    }
};