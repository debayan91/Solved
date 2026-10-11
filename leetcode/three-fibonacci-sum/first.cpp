class Solution {
public:
    bool threeFibonacciSum(int n) {
        if(n < 2 || n % 2 > 0) return 0;
        int a = n / 2, x = 1, y = 2;
        while(1){
            if(x >= a) break;int next = x + y; x = y, y = next;
            
        }
        return x == a;
    }
};