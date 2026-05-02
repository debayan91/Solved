class Solution {
public:
    int climbStairs(int n) {
        if(n < 3) return n;
        int one = 1;
        int two = 2;
        for(int i = 3; i <= n; i++){
            int next = one + two;
            one = two;
            two = next;
        }
        return two;
    }
};