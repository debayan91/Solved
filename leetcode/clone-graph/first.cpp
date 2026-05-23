/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == NULL)
            return NULL;

        unordered_map<Node*, Node*> graph; // old ndoe -> new node

        queue<Node*> q;
        q.push(node);

        // this makes a mapping from original -> new with values only and makes
        // all the new nodes
        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            graph[current] = new Node(current->val);
            for(Node* n : current->neighbors){
                if(graph.count(n) == 0) q.push(n);
            }
        }

        // now for the neighbors
        for (auto& [key, value] : graph) {
            vector<Node*> v;
            for (Node* n : key->neighbors)
                v.push_back(graph[n]);
            value->neighbors = v;
        }

        return graph[node];
    }
};