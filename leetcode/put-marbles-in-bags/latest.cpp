class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        vector<long long> p; int n = size(weights);

        // all pairs adj sums
        for(int i = 0; i < n - 1; i++){
            p.push_back(weights[i] + weights[i + 1]);
        }

        sort(begin(p), end(p));

        long long a = 0, b = 0;

        int index = size(p) - 1;

        for(int i = 0; i < k - 1; i++){
            a += p[i];
            b += p[index--];
        }

        return b - a;
    }
};