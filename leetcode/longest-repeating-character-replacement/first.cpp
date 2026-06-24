class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freq;
        int res = 0;
        int start = 0;
        int mx = 0;
        for (int i = 0; i < size(s); i++) {
            freq[s[i]]++;
            mx = max(mx, freq[s[i]]); // freq of max element
            if (i - start + 1 - mx > k) {
                freq[s[start]]--;
                start++;
            }
            res = max(res, i - start + 1);
        }
        return res;
    }
};