class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();

        vector<int> last(26, -1);

        for (int i = 0; i < n; i++) {
            last[s[i] - 'a'] = i;
        }

        vector<int> res;

        int i = 0;

        while (i < n) {
            int end = last[s[i] - 'a'];

            for (int j = i; j <= end; j++) {
                end = max(end, last[s[j] - 'a']);
            }

            res.push_back(end - i + 1);
            i = end + 1;
        }

        return res;
    }
};