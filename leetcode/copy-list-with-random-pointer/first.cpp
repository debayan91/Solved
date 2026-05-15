/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;
        unordered_map<Node*, int> routes;

        vector<Node*> org;
        vector<Node*> cpy;

        Node* temp = head;

        int index = 0;

        Node* root = new Node(head->val); // first node
        Node* t = root;

        routes[temp] = index++;
        temp = temp->next;

        org.push_back(temp);
        cpy.push_back(t);

        while (temp != nullptr) {
            routes[temp] = index++;
            org.push_back(temp);

            t->next = new Node(temp->val);

            temp = temp->next;
            t = t->next;

            cpy.push_back(t);
        }

        temp = head;
        t = root;

        while (temp != nullptr) {
            Node* random = temp->random;
            if (random != nullptr) {
                int r_index = routes[random];
                Node* trand = cpy[r_index];
                t->random = trand;
            }
            temp = temp->next;
            t = t->next;
        }
        return root;
    }
};