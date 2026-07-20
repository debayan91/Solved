class Solution {
public:
    vector<bool> isPrime(int n) {
        vector<bool> prime(n + 1, true);

        prime[0] = prime[1] = false;

        for (int i = 2; i * i <= n; i++) { // 2 to root(n)
            if (prime[i]) {
                for (int j = i * i; j <= n; j += i) // from i sqauared to n 
                    prime[j] = false;
            }
        }

        return prime;
    }
    vector<vector<int>> findPrimePairs(int n) {
        auto p = isPrime(n);
        vector<vector<int>> res;
        vector<int> pr;
        for(int i = 2; i < n + 1; i++) if(p[i]) pr.push_back(i);
        int i = 0;
        int j = size(pr) - 1;
        while(i <= j){
            int sum = pr[i] + pr[j];
            if(sum == n){
                res.push_back({pr[i], pr[j]});
                i++;
                j--;
            } else if(sum > n){
                j--;
            } else {
                i++;
            }
        }
        return res;
    }
};