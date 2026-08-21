class Solution {
public:
    string largestPalindromic(string num) {
        vector<int> a(10, 0);
        for (char c : num)
            a[c - '0']++;
        string res = "";
        int m = -1;
        for (int i = 9; i >= 0; i--) {
            if (a[i] % 2 && m == -1)
                m = i;
            for (int j = 0; j < a[i] / 2; j++)
                res += to_string(i);
        }
        string r = res;
        reverse(begin(r), end(r));
        if (m == -1) {
            res = res + r;
        }else res = res + to_string(m) + r;
        int l = 0, rr = size(res) - 1;
        while(res[l] == '0' && res[rr] == '0'){
            l++;
            rr--;
        }
        res = res.substr(l, rr - l + 1);
        return size(res) == 0 ? "0" : res;
    }
};