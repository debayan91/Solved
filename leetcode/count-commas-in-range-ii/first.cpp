class Solution {
public:
    long long countCommas(long long n) {
        if(n < 1000) return 0;
        else if(n < 1e6){
            return 1 * (n - 1e3 + 1);
        }
        else if(n < 1e9){
            long long k = 1 * (1e6 - 1 - 1e3 + 1);
            k += 2 * (n - 1e6 + 1);
            return k;
        } else if(n < 1e12){
            long long k = 1 * (1e6 - 1 - 1e3 + 1);
            k += 2 * (1e9 - 1 - 1e6 + 1);
            k += 3 * (n - 1e9 + 1);
            return k;
        }else{
            long long k = 1 * (1e6 - 1 - 1e3 + 1);
            k += 2 * (1e9 - 1 - 1e6 + 1);
            k += 3 * (1e12 - 1 - 1e9 + 1);
            k += 4 * (n - 1e12 + 1);
            if(n == 1e15) k++;
            return k;
        }
    }
};