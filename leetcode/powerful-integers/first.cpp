class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, unsigned long long bound) {
        if(bound < 2) return {};
        if(x == 1 && y == 1){
            return {2};
        } else if(x == 1){
            unordered_set<int> st;
            unsigned long long a = 1;
            while(1){
                int k = 1 + a;
                if(k <= bound){
                    st.insert(k);
                }
                else break;
                a *= y;
            }
            vector<int> res(begin(st), end(st));
            return res;
        } else if(y == 1){
            y = x;
            unordered_set<int> st;
            unsigned long long a = 1;
            while(1){
                int k = 1 + a;
                if(k <= bound){
                    st.insert(k);
                }
                else break;
                a *= y;
            }
            vector<int> res(begin(st), end(st));
            return res;
        }
        unsigned long long a = 1;
        unsigned long long b = 1;
        unordered_set<int> st;
        while(1){
            while(1){
                int k = a + b;
                b *= y;
                if(k <= bound){
                    st.insert(k);
                }
                else break;
            }
            b = 1;
            a *= x;
            if(a + 1 > bound) break;
        }
        vector<int> res(begin(st), end(st));
        return res;
    }
};