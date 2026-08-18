class Solution {
public:
    int rangeBitwiseAnd(int l, int r) {
        return r > l ? rangeBitwiseAnd(l / 2, r / 2) << 1 : l;
    }
};