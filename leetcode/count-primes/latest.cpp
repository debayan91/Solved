class Solution {
public:
    int countPrimes(int n) {
        vector<bool> numbers(n, true);
        for(int i = 2; i * i < n; i++){
            if(numbers[i]) for(int j = i * i; j < n; j += i) numbers[j] = false;
        }
        int count = 0;
        for(int i = 2; i < n; i++) if(numbers[i]) count++;
        return count;
    }
};