class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = size(s);
        int count = 0;
        for(char c : s) if(c == '1') count++;
        string ss(n, '0');
        ss[n - 1] = '1';
        count--;
        int i = 0;
        while(count--){
            ss[i++] = '1';
        }
        return ss;
    }
};