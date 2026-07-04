class Solution {
public:
    int minOperations(string s1, string s2) {
        int n = size(s1);

        long long a = 0;
        long long b = INT_MAX;
        for(int i = 0; i < n; i++){
            long long an = INT_MAX;
            long long bn = INT_MAX;

            char c1 = s1[i];
            char c2 = s2[i];

            if(a != INT_MAX){
                if(c1 == '0' && c2 == '0') an = min(a, an);
                if(c1 == '0' && c2 == '1') an = min(a + 1, an);
                if(c1 == '1' && c2 == '1') an = min(a, an);
            }

            if(b != INT_MAX){
                long long cost = b;
                if(c1 == '0') cost = cost + 1;
                else cost += 0;
                if(c2 == '1') cost += 1;
                an = min(an, cost);
            }

            if(a != INT_MAX && i < n - 1){
                long long cost = a + 1;
                if(c1 == '0') cost = cost + 1;
                else cost += 0;
                if(c2 == '1') cost += 1;
                bn = min(bn, cost);
            }

            if(b != INT_MAX && i < n - 1){
                long long cost = b;
                if(c1 == '0') cost = cost + 1;
                else cost += 0;
                cost += 2;
                if(c2 == '1') cost += 1;
                bn = min(bn, cost);
            }

            a = an;
            b = bn;
            
        }
        if(a >= INT_MAX) return -1;
        else return a;
    }
};