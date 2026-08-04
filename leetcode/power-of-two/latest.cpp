class Solution {
public:
    bool isPowerOfTwo(int x) {
        if (x < 0 || __builtin_popcount(x) != 1)
            return false;
        return true;
    }
};