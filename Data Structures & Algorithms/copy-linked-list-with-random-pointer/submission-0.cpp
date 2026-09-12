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

#define sz(a) (int)(a).size()

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // 1st pass: store every node into a map (address -> idx)
        // 2nd pass: find the "index" that each random pointer points to and store it in a map (idx of node -> idx of random pointer); a nullptr should be represented with `-1`
        // 3rd pass: create a deep copy of each node from the original list with their values
        // 4th pass: for each node in the new list, reference the map from (2) to point it to the correct node
        int i = 0;
        unordered_map<Node*, int> idx;
        vector<Node*> order;
        Node *cur = head;
        while (cur) {
            idx[cur] = i++;
            order.push_back(cur);
            cur = cur->next;
        }

        vector<int> rands(i);
        cur = head;
        while (cur) {
            rands[idx[cur]] = cur->random ? idx[cur->random] : -1;
            cur = cur->next;
        }

        Node dummy(0);
        cur = &dummy;
        for (i = 0; i < sz(order); ++i) {
            cur->next = new Node(order[i]->val);
            // Reuse `order` to now store the new node pointers
            order[i] = cur->next;
            cur = cur->next;
        }

        cur = dummy.next;
        for (i = 0; i < sz(order); ++i) {
            cur->random = rands[i] != -1 ? order[rands[i]] : nullptr;
            cur = cur->next;
        }

        return dummy.next;
    }
};
