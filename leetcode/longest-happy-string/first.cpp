class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string res = "";

        while (a > 0 || b > 0 || c > 0) {
            bool change = 0;
            int n = size(res);
            bool k = n > 1;

            // a is currently the maximum
            if (a >= b && a >= c) {
                if (a && !(k && res[n - 1] == 'a' && res[n - 2] == 'a')) {
                    res += 'a';
                    a--;
                    change = 1;
                }
                else if (b && !(k && res[n - 1] == 'b' && res[n - 2] == 'b')) {
                    res += 'b';
                    b--;
                    change = 1;
                }
                else if (c && !(k && res[n - 1] == 'c' && res[n - 2] == 'c')) {
                    res += 'c';
                    c--;
                    change = 1;
                }
            }

            // b is currently the maximum
            else if (b >= a && b >= c) {
                if (b && !(k && res[n - 1] == 'b' && res[n - 2] == 'b')) {
                    res += 'b';
                    b--;
                    change = 1;
                }
                else if (a && !(k && res[n - 1] == 'a' && res[n - 2] == 'a')) {
                    res += 'a';
                    a--;
                    change = 1;
                }
                else if (c && !(k && res[n - 1] == 'c' && res[n - 2] == 'c')) {
                    res += 'c';
                    c--;
                    change = 1;
                }
            }

            // c is currently the maximum
            else {
                if (c && !(k && res[n - 1] == 'c' && res[n - 2] == 'c')) {
                    res += 'c';
                    c--;
                    change = 1;
                }
                else if (a && !(k && res[n - 1] == 'a' && res[n - 2] == 'a')) {
                    res += 'a';
                    a--;
                    change = 1;
                }
                else if (b && !(k && res[n - 1] == 'b' && res[n - 2] == 'b')) {
                    res += 'b';
                    b--;
                    change = 1;
                }
            }

            if (!change)
                break;
        }

        return res;
    }
};