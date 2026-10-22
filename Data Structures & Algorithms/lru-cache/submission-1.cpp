class LRUCache {

    struct Node {
        Node *prev = nullptr, *next = nullptr;
        int key, val;
        Node(int k, int v) : key(k), val(v) {}
        Node() : Node(0, 0) {}
    };
    
    int cap;
    // Insert at head, remove at tail
    Node head, tail;
    unordered_map<int, Node*> mp;
    
public:
    LRUCache(int capacity) : cap(capacity) {
        head.next = &tail;
        tail.prev = &head;
    }
    
    int get(int key) {
        if (!mp.count(key)) return -1;

        // Disconnect node and move to head
        Node *node = mp[key];
        node->prev->next = node->next;
        node->next->prev = node->prev;

        node->prev = &head;
        node->next = head.next;
        head.next = node;
        node->next->prev = node;

        return node->val;
    }
    
    void put(int key, int value) {
        if (mp.count(key)) {
            get(key);
            mp[key]->val = value;
        } else {
            Node *node = new Node(key, value);
            node->prev = &head;
            node->next = head.next;
            head.next = node;
            node->next->prev = node;
            mp[key] = node;

            --cap;
            if (cap == -1) {
                // Evict from the tail
                Node *del = tail.prev;
                del->prev->next = &tail;
                tail.prev = del->prev;
                mp.erase(del->key);
                delete del;
                ++cap;
            }
        }
    }
};
