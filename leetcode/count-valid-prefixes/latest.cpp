class Solution {
public:
    int countValidPrefixes(string s) {
        int a = 0, b=0;
        int res = 0;
        for(char c : s){
            if(c == '1') a++;
            else b++;
            if(abs(a - b) < 2) res++;
        }
        return res;
    }
};