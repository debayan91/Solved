class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res(n);
        for (int i = 0; i < n; i++)
            res[i] = i + 1;
        sort(begin(res), end(res),
             [](int a, int b) { return to_string(a) < to_string(b); });
        return res;
    }
};