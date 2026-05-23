class Solution {
public:
    vector<int> lps(string p) {
        vector<int> a(p.size(), 0);

        int j = 0;

        for(int i = 1; i < p.size(); i++) {
            while(j > 0 && p[i] != p[j]) {
                j = a[j - 1];
            }

            if(p[i] == p[j]) {
                j++;
            }

            a[i] = j;
        }

        return a;
    }

    string longestPalindrome(string s) {
        string r = s;
        reverse(r.begin(), r.end());

        int n = s.size();

        string best = "";

        for(int sh = -(n - 1); sh <= (n - 1); sh++) {

            string t = "";

            for(int i = 0; i < n; i++) {
                int j = i + sh;

                if(j < 0 || j >= n) continue;

                if(s[i] == r[j]) {
                    t += s[i];
                }
                else {
                    if(t.size() > best.size()) {
                        string x = t;
                        string y = x;
                        reverse(y.begin(), y.end());

                        if(x == y) best = x;
                    }

                    t = "";
                }
            }

            if(t.size() > best.size()) {
                string x = t;
                string y = x;
                reverse(y.begin(), y.end());

                if(x == y) best = x;
            }
        }

        return best;
    }
};