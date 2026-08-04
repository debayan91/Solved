class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> need;
        for (auto &word : words) need[word]++;
        int k = words[0].size(); // k letters
        int n = words.size(); // n words
        int pn = n * k; // permutation length
        if (s.size() < pn) return {};
        vector<int> res;
        for (int i = 0; i < s.size() - pn + 1; i++) { // when we can still have a permutation starting from i
            unordered_map<string, int> have;
            for (int j = 0; j < n; j++) { // check n consecutive words
                string word = s.substr(i + j * k, k); // check words of len k starting from i
                have[word]++;
            }
            if (have == need) res.push_back(i); // do we got a permutation?
        }
        return res;
    }
};