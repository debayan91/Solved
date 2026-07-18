class TrieNode {
public:
    TrieNode* child[26];
    bool isEnd;

    TrieNode() {
        for (int i = 0; i < 26; i++) child[i] = nullptr;
        isEnd = false;
    }
};

class WordDictionary {
public:
    TrieNode* root;

    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;

        for (char c : word) {
            int idx = c - 'a';
            if (curr->child[idx] == nullptr)
                curr->child[idx] = new TrieNode();

            curr = curr->child[idx];
        }

        curr->isEnd = true;
    }

    bool dfs(TrieNode* node, string &word, int idx) {
        if (node == nullptr) return false;

        if (idx == word.size())
            return node->isEnd;

        if (word[idx] == '.') {
            for (int i = 0; i < 26; i++) {
                if (node->child[i] && dfs(node->child[i], word, idx + 1))
                    return true;
            }
            return false;
        }

        return dfs(node->child[word[idx] - 'a'], word, idx + 1);
    }
    
    bool search(string word) {
        return dfs(root, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */