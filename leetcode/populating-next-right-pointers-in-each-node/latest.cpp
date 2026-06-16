/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        if (!root)
            return root;
        root->next = NULL;
        Node* b = root;
        while (root->left) {
            // connect children
            root->left->next = root->right;
            root->right->next = NULL;

            Node* a = root;
            // if we got a neighbor
            if (root->next) {
                while (root->next) {
                    root->left->next = root->right;
                    root->right->next = root->next->left;
                    root = root->next;
                }
                root->left->next = root->right;
                root->right->next = NULL;
            }

            root = a->left;
        }
        return b;
    }
};