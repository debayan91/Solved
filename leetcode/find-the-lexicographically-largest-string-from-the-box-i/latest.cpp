class Solution {
public:
    string answerString(string word, int k) {
        int n = word.size();
        if (1 == k)
            return word;
        int len = n - k + 1;
        string res = word.substr(0, len);
        int a = 0;
        for (int i = 1; i < n; i++) {
            if (word[a] <= word[i]) {
                string temp = word.substr(i, len);
                if (temp > res) {
                    res = temp;
                    a = i;
                }
            }
        }
        return res;
    }
};