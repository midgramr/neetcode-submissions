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
    unordered_map<Node*, Node*> mp;
    
public:
    Node* cloneGraph(Node* node) {
        // Make and store reference to node first time it's seen; reuse reference on subsequent visits
        // Ensure each node is visited once
        // Recursively clone each neighboring node before adding edges (since neighboring nodes' copies might not exist yet)
        if (!node) return nullptr;
        if (mp.count(node)) return mp[node];
        Node *copy = new Node(node->val);

        // Save the incomplete copy in `mp` so it isn't revisited if the graph has a loop
        mp[node] = copy;

        for (auto nei : node->neighbors) {
            copy->neighbors.push_back(cloneGraph(nei));
        }

        return copy;
    }
};
