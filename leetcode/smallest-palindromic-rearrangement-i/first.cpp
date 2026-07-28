class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> a(26, 0);
        for (char c : s)
            a[c - 'a']++;
        string res = "";
        char cc = '.';
        for (int i = 0; i < 26; i++) {
            if (a[i] % 2 == 0) {
                for (int j = 0; j < a[i] / 2; j++)
                    res += 'a' + i;
            } else {
                cc = 'a' + i;
                a[i]--;
                for (int j = 0; j < a[i] / 2; j++)
                    res += 'a' + i;
            }
        }
        if(cc != '.') res += cc;
        for (int i = 25; i >= 0; i--) {
            for (int j = 0; j < a[i] / 2; j++)
                res += 'a' + i;
        }
        return res;
    }
};