class Solution {
public:
    unordered_set<string> getDivisors(string s) {
        unordered_set<string> st;
        int n = s.size();

        for (int len = 1; len <= n; len++) {
            if (n % len)
                continue; // length must divide n

            string t = s.substr(0, len);

            bool ok = true;
            for (int i = 0; i < n; i += len) {
                if (s.substr(i, len) != t) {
                    ok = false;
                    break;
                }
            }

            if (ok)
                st.insert(t);
        }

        return st;
    }
    string gcdOfStrings(string str1, string str2) {
        auto a = getDivisors(str1);
        auto b = getDivisors(str2);
        string mx = "";
        for(auto s : a){
            if(b.count(s)) mx = max(mx, s);
        }
        return mx;
    }
};