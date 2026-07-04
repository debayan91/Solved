class Solution {
public:
    int tribonacci(int n) {
        if(n == 0) return 0;
        int a = 0;
        int b = 1;
        int c = 1;
        for(int i = 0; i < n - 2; i++){
            int t = c;
            c = a + b + c;
            a = b;
            b = t;
        }
        return c;
    }
};