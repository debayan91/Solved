class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int x1 = x;
        int x2 = x;
        long long r = 0;

        int digits = 0;
        long long p = 1;
        while(x1>0){
            x1/=10;
            digits++;
            if(digits>1) p *= 10;
        }
        while(x2>0){
            if(p>0) r = r + p*(x2%10);
            else r+= x2%10;
            x2 /= 10;
            p /= 10;
        }
        if(r>INT_MAX) return false;

        if(r == x) return true;
        return false;
    }
};