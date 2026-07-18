class WordDictionary {
public:
    unordered_map<int, vector<string>> mp;

    WordDictionary() {
        
    }
    
    void addWord(string word) {
        mp[word.size()].push_back(word);
    }
    
    bool search(string word) {
        auto &v = mp[word.size()];

        for (string &s : v) {
            bool ok = true;

            for (int i = 0; i < word.size(); i++) {
                if (word[i] != '.' && word[i] != s[i]) {
                    ok = false;
                    break;
                }
            }

            if (ok) return true;
        }

        return false;
    }
};