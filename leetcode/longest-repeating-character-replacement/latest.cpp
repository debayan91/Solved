class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int res = 0;
        int start = 0;
        int mx = 0;
        for (int i = 0; i < size(s); i++) {
            freq[s[i] - 'A']++;
            mx = max(mx, freq[s[i] - 'A']); // freq of max element
            if (i - start + 1 - mx > k) {
                freq[s[start] - 'A']--;
                start++;
            }
            res = max(res, i - start + 1);
        }
        return res;
    }
};