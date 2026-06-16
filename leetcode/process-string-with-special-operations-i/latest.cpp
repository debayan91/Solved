class Solution {
public:
    string processStr(string s) {
        string a = "";
        for (char c : s) {
            if (c == '*') {
                if (size(a) > 0) a.pop_back();
            } else if (c == '#') {
                a = a + a;
            } else if (c == '%') {
                reverse(begin(a), end(a));
            } else {
                a = a + c;
            }
        }
        return a;
    }
};