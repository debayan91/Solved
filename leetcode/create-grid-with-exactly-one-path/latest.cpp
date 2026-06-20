class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> res;
        for (int i = 0; i < m - 1; i++) {
            string s = "";
            s += '.';
            for (int j = 0; j < n - 1; j++) {
                s += '#';
            }
            res.push_back(s);
        }
        string s = "";
        s += '.';
        for (int j = 0; j < n - 1; j++) {
            s += '.';
        }
        res.push_back(s);
        // for (int i = 0; i < m; i++) {
        //     cout << res[i] << endl;
        // }
        return res;
    }
};