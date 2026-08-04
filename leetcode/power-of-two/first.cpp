class Solution {
public:
    bool isPowerOfTwo(int x) {
        if (x < 0 || x != 1 && x & 1)
            return false;
        if(__builtin_popcount(x) != 1) return false;
        return true;
    }
};