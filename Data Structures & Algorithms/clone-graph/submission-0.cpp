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
    // Store mapping from old node -> new node
    // When we encounter an old node that we haven't seen yet, we create a new mapping on demand
    unordered_map<Node*, Node*> mp;
    
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        if (mp.count(node)) return mp[node];

        Node *clone = new Node(node->val);
        mp[node] = clone;
        // Edge case: there could be a loop that points to a node currently being constructed
        for (auto neighbor : node->neighbors) {
            clone->neighbors.push_back(cloneGraph(neighbor));
        }
        return clone;
    }
};
