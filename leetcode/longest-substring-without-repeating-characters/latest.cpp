class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int mx = 0;
        int start = 0;
        int end = 0;
        unordered_map<char, int> map;
        for (int i = 0; i < s.size(); i++) {
            int current = 1;
            if (map.count(s[i]) == 0 || map[s[i]] < start) {
                map[s[i]] = i;
                current = i - start + 1;
            } else {
                end = i - 1;
                current = end - start + 1;
                start = map[s[i]] + 1;
                map[s[i]] = i;
            }
            mx = max(current, mx);
            // cout << mx << " ";
        }
        return mx;
    }
};