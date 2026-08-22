class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int mw) {
        vector<string> res;
        int n = size(words);
        int i = 0;
        while (i < n) {
            vector<string> c;
            int sum = 0;
            while (i < n && sum + size(words[i]) <= mw) {
                c.push_back(words[i] + " ");
                sum += size(words[i]) + 1;
                i++;
            }
            int sz = size(c);
            c[sz - 1].pop_back();
            sum--;
            if (sz == 1) {
                string spaces(mw - sum, ' ');
                res.push_back(c[0] + spaces);
                continue;
            }
            int left = mw - sum;
            int slots = sz - 1;
            int fill = left / slots;
            int rem = left % slots;

            if (i >= n) {
                string s = "";
                for (int j = 0; j < sz; j++) {
                    s += c[j];
                }
                string spaces(mw - size(s), ' ');
                res.push_back(s + spaces);
                continue;
            }
            string s = "";
            string spaces(fill, ' ');
            for (int j = 0; j < sz; j++) {
                s += c[j];
                if (j != sz - 1)
                    s += spaces;
                if (rem) {
                    s += " ";
                    rem--;
                }
            }
            res.push_back(s);
        }
        return res;
    }
};