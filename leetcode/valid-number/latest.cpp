class Solution {
public:
    bool isNumber(string s) {
        int n = size(s), e = 0, d = 0, a = 0, b = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '.')
                d++;
            if (s[i] == 'e' || s[i] == 'E')
                e++;
            if (isdigit(s[i])) {
                if (e)
                    b++;
                else
                    a++;
            }
            if ((s[i] == '+' || s[i] == '-') && i != 0 &&
                (s[i - 1] != 'e' && s[i - 1] != 'E'))
                return 0;
            else if (isalpha(s[i]) && (s[i] != 'e' && s[i] != 'E'))
                return 0;
            else if (d > 1 || e > 1)
                return 0;
            else if (s[i] == '.' && e)
                return 0;
            else if ((i == 0 || i == n - 1) && (s[i] == 'e' || s[i] == 'E'))
                return 0;
            else if (i == 0 && i == n - 1 && s[i] == '.')
                return 0;
            else if ((s[i] == 'e' || s[i] == 'E') && !a)
                return 0;
        }
        if ((e && !b) || !a)
            return 0;
        return 1;
    }
};