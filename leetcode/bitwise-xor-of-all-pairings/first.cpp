class Solution {
public:
    int xorAllNums(vector<int>& a, vector<int>& b) {
        int m = size(a), n = size(b);
        int x1 = 0, x2 = 0;
        for(int i : a) x1 ^= i;
        for(int i : b) x2 ^= i;
        if(m % 2 == 0 && n % 2 == 0){
            return 0;
        }
        if(m % 2 == 0){
            return x1;
        }
        if(n % 2 == 0){
            return x2;
        }
        return x1 ^ x2;
    }
};