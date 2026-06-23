class Solution {
public:
    int mySqrt(unsigned long long x) {
        for(unsigned long long i = 0; i < x - 1; i++){
            if(i * i == x) return i;
            else if(i * i < x && (i + 1) * (i + 1) > x) return i;
        }
        return 1;
    }
};