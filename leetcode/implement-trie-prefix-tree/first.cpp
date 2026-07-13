class Trie {
public:
    unordered_set<string> st;
    class Node {
    public:
        bool end;
        vector<Node*> v;
        Node() {
            end = false;
            v.assign(26, nullptr);
        }
    };
    Node* root;
    Trie() { root = new Node(); }

    void insert(string word) {
        st.insert(word);
        Node* temp = root;
        for (int i = 0; i < size(word); i++) {
            char c = word[i];
            int index = c - 'a';
            if (temp->v[index] == NULL) {
                temp->v[index] = new Node();
            }
            temp = temp->v[index];
            if (i == size(word) - 1) {
                temp->end = true;
            }
        }
    }

    bool search(string word) { return st.count(word); }

    bool startsWith(string prefix) {
        Node* temp = root;
        for (int i = 0; i < size(prefix); i++) {
            char c = prefix[i];
            int index = c - 'a';
            if (temp->v[index] == NULL) {
                return false;
            }
            temp = temp->v[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */