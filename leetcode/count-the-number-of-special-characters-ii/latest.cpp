class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char, int> mp;
        for (int i = 0; i < word.size(); i++) {
            char c = word[i];
            if (islower(c)) {
                mp[c] = i;
            }
            if (isupper(c) && mp.count(c) == 0) {
                mp[c] = i;
            }
        }
        int count = 0;
        for (auto& [ch, index] : mp) {
            if (islower(ch)) {
                char upper = toupper(ch);
                if (mp.count(upper) && mp[upper] > index) {
                    count++;
                }
            }
        }
        return count;
    }
};