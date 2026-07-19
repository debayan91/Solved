class Solution {
public:
    int minOperations(int n) {
        int k = 0;
        for(int i = 1; i <= n; i++) k += i * 2 + 1;
        k /= n;
        int ops = 0;
        for(int i = 1; i <= n; i++) ops += abs(i * 2 + 1 - k);
        return ops / 2;
    }
};