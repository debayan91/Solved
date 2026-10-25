class Solution {
public:
    int countStaircase(vector<int>& a) {
        int n = size(a);
        long long s = 0;
        int mx = *max_element(begin(a), end(a));
        vector<int> f(mx + 1, 0), r(mx + 1, 0), order; order.reserve(500);
        for(int i = 0; i < n; i++){
            order.clear();
            for(int j = i; j < n; j++){
                ///
                int x = a[j];
                if(!r[x]){
                    int k  = size(order) + 1;
                    if(1LL * k * (k + 1) / 2 > n - i) break;
                    order.push_back(x); r[x] = size(order);
                }
                f[x]++;
                if(f[x] > r[x]) break;
                int k = size(order), l = j - i + 1, need = k * (k + 1) / 2;
                if(need == l){
                    bool flag = 1;
                    for(int ii = 0; ii < k; ii++){
                        if(f[order[ii]] != ii + 1){
                            flag = 0; break;
                        }
                    }
                    if(flag) s++;
                }
            }
            for(int x : order){f[x] = r[x] = 0;}
        }
        return s;
    }
};