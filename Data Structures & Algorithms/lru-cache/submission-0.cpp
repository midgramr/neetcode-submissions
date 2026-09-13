#define sz(a) (int)(a).size()
class LRUCache {
    // Need a linked list to track which keys were most recently used; unlink and relink when a key gets updated; append to the end when new key added; pop from front for eviction
    // Within the linked list, we need a reference to the key that represents that node
    // Within our hashtable, we should store key -> node pointer. We can reuse the node here to store the value associated with the key
private:
    struct Node {
        int key, value;
        Node *next, *prev;
        Node() : key(0), value(0), next(nullptr), prev(nullptr) {}
        Node(int k, int v) : key(k), value(v), next(nullptr), prev(nullptr) {}
    };

    unordered_map<int, Node*> kv;
    Node head, tail;
    int cap;

public:
    LRUCache(int capacity) : cap(capacity) {
        head.next = &tail;
        tail.prev = &head;
    }
    
    int get(int key) {
        // Should not trigger any evictions, just reordering
        if (!kv.count(key)) return -1;
        Node *node = kv[key];
        // Disconnect node
        node->prev->next = node->next;
        node->next->prev = node->prev;
        // Reconnect at the end
        node->prev = tail.prev;
        node->next = &tail;
        node->prev->next = node;
        tail.prev = node;
        return node->value;
    }
    
    void put(int key, int value) {
        if (kv.count(key)) {
            // Update
            // Side-effect only: reorder
            get(key);
            kv[key]->value = value;
        } else {
            if (sz(kv) == cap) {
                // Evict if full
                Node *del = head.next;
                head.next = del->next;
                del->next->prev = &head;
                kv.erase(del->key);
                delete del;
            }
            Node *node = new Node(key, value);
            kv[key] = node;
            node->next = &tail;
            node->prev = tail.prev;
            tail.prev = node;
            node->prev->next = node;
        }
    }
};
