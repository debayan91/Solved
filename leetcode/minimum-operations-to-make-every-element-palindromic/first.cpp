class Solution {
public:
    long long minOperations(vector<int>& nums) {
        static vector<long long> even, odd; static bool guard = 0;


        if(!guard){
        auto add = [&](long long p){
            if(p > 0 && p <= 2LL * 1e9){
                if(p % 2) odd.push_back(p); else even.push_back(p);
            }
        };
        for(long long i = 0; i <= 2 * 1e5; i++){
            long long p = i, t = i / 10;
            while(t){
                p = p * 10 + t % 10; t /= 10;
            }
            add(p);

            p = i, t = i;
            while(t){
                p = p * 10 + t % 10; t /= 10;
            }
            add(p);
        }

        sort(begin(even), end(even)); sort(begin(odd), end(odd)); guard = 1; }

        long long res = 0; for(long long x : nums){
            auto& v = (x % 2) ? odd : even;
            auto it = lower_bound(begin(v), end(v), x);



            long long b = -1; 
            if(it != end(v)) b = (*it - x) / 2;

            if(it != begin(v)){
                long long c = (x - *prev(it)) / 2; if(b == -1 || c < b) b = c;
            }

            res += b;
        }
        return res;
    }
};