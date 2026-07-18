class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> need(128, 0), window(128, 0);

        for (char c : t)
            need[(unsigned char)c]++;

        int required = 0;
        for (int x : need)
            if (x) required++;

        int formed = 0;
        int start = 0;
        int mn = INT_MAX;
        int bestStart = -1;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            window[(unsigned char)c]++;

            if (need[(unsigned char)c] &&
                window[(unsigned char)c] == need[(unsigned char)c])
                formed++;

            while (formed == required) {
                int len = i - start + 1;
                if (len < mn) {
                    mn = len;
                    bestStart = start;
                }

                char left = s[start];
                window[(unsigned char)left]--;

                if (need[(unsigned char)left] &&
                    window[(unsigned char)left] < need[(unsigned char)left])
                    formed--;

                start++;
            }
        }

        return bestStart == -1 ? "" : s.substr(bestStart, mn);
    }
};