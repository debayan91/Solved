class Solution {
public:
    int largestInteger(int n, int s) {
        int k = s / 9;
        int r = s % 9;
        if(k > n || (r > 0 && k == n)) return -1;
        string a = "";
        for(int i = 0; i < k; i++) a += '9';
        if(size(a) == n){
            
        } else {
            int b = n - size(a) - (r > 0);
            if(r) a += '0' + r;
            for(int i = 0; i < b; i++){
                a += '0';
            }
        }
        return stoi(a);
    }
};