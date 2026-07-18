class TrieNode {
public:
    TrieNode* child[26];
    bool isEnd;
    string word; // in order to push

    TrieNode() {
        for (int i = 0; i < 26; i++)
            child[i] = nullptr;
        isEnd = false;
        word = "";
    }
};

class Solution {
public:
    TrieNode* root;
    vector<string> ans;

    void insert(string &word) {
        TrieNode* curr = root;

        for (char c : word) {
            int idx = c - 'a';
            if (curr->child[idx] == nullptr)
                curr->child[idx] = new TrieNode();

            curr = curr->child[idx];
        }

        curr->isEnd = true;
        curr->word = word;
    }

    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node) {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size())
            return;

        if (board[i][j] == '#')
            return; // visited

        char c = board[i][j];

        if (node->child[c - 'a'] == nullptr) // it aint moving ahead
            return;

        node = node->child[c - 'a']; // move along

        if (node->isEnd) {
            ans.push_back(node->word);
            node->isEnd = false; // we found it -> no longer needed ending
        }

        board[i][j] = '#'; // visited

        dfs(board, i + 1, j, node);
        dfs(board, i - 1, j, node);
        dfs(board, i, j + 1, node);
        dfs(board, i, j - 1, node);

        board[i][j] = c;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TrieNode();

        for (string &word : words)
            insert(word);

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                dfs(board, i, j, root);
            }
        }

        return ans;
    }
};