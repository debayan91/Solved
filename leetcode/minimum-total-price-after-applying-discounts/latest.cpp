class Solution {
public:
    double minPrice(vector<int>& p, vector<int>& d) {
        int pn = size(p), dn = size(d);
        sort(begin(p), end(p), greater<int>());
        sort(begin(d), end(d), greater<int>());
        double sum = 0;
        int i = 0, j = 0;
        while(i < pn && j < dn){
            sum += p[i] * (100.0 - d[j]) / 100.0;
            i++; j++;
        }
        while(i < pn){
            sum += p[i]; i++;
        }
        return sum;
    }
};