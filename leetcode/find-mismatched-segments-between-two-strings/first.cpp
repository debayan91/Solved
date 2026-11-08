class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        vector<vector<string>> res;
        int n = size(s1);
        for (int i = 0; i < n;) {
            if (s1[i] == s2[i]) {
                i++;
                continue;
            }

            string x, y;
            while (i < n && s1[i] != s2[i]) {
                x += s1[i], y += s2[i];
                i++;
            }
            res.push_back({x, y});
        }
        return res;
    }
};