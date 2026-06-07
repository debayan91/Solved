class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int sum = 0;
        for(int x = 0; x <= n + k; x++){
            if((n & x) == 0 && abs(n - x) <= k) sum += x;
        }
        return sum;
    }
};

