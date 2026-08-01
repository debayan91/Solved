class Solution {
public:
    int res = 0;
    void b(int index, vector<string>& words, vector<int>& count, vector<int>& score, int sum) {
        if (index == words.size()) {
            res = max(res, sum);
            return;
        }
        b(index + 1, words, count, score, sum);
        bool flag = true;
        int csum = 0;
        for (char c : words[index]) {
            count[c - 'a']--;
            if (count[c - 'a'] < 0) flag = false;
            csum += score[c - 'a'];
        }
        if (flag) b(index + 1, words, count, score, sum + csum);
        for (char c : words[index]) count[c - 'a']++;
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> count(26, 0);
        for (char c : letters) count[c - 'a']++;
        b(0, words, count, score, 0);
        return res;
    }
};