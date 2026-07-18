class TrieNode {
public:
    TrieNode* child[26];
    bool isEnd;
    string word;

    TrieNode() {
        for (int i = 0; i < 26; i++)
            child[i] = nullptr;
        isEnd = false;
    }
};

class Solution {
public:
    TrieNode* root;
    vector<string> ans;
    vector<vector<bool>> visited;

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

        if (visited[i][j])
            return;

        char c = board[i][j];

        if (node->child[c - 'a'] == nullptr)
            return;

        node = node->child[c - 'a'];

        if (node->isEnd) {
            ans.push_back(node->word);
            node->isEnd = false;
        }

        visited[i][j] = true;

        dfs(board, i + 1, j, node);
        dfs(board, i - 1, j, node);
        dfs(board, i, j + 1, node);
        dfs(board, i, j - 1, node);

        visited[i][j] = false;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TrieNode();

        for (string &word : words)
            insert(word);

        visited = vector<vector<bool>>(board.size(), vector<bool>(board[0].size(), false));

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                dfs(board, i, j, root);
            }
        }

        return ans;
    }
};