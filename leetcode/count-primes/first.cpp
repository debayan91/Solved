class Solution {
public:
    bool isPrime(int n) {
        if (n < 2)
            return false;
        if (n == 2)
            return true;
        if (n % 2 == 0)
            return false;

        for (int i = 3; i * i <= n; i += 2) {
            if (n % i == 0)
                return false;
        }

        return true;
    }
    int countPrimes(int n) {
        vector<int> primes;
        for (int i = 2; i * i < n; i++) {
            if(isPrime(i)) primes.push_back(i);
        }
        vector<bool> numbers(n, true);
        for(int p : primes){
            for(int i = p * 2; i < numbers.size(); i += p){
                numbers[i] = false;
            }
        }
        int count = 0;
        for(int i = 2; i < numbers.size(); i++) if(numbers[i]) count++;
        return count;
    }
};