class LRUCache {
private:
    struct Node {
        int key, value;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            prev = nullptr;
            next = nullptr;
        }
    };
    int capacity;
    unordered_map<int, Node*> mp;
    Node* head;
    Node* tail;
    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    void insert(Node* node) {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }
    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;
        Node* node = mp[key];
        remove(node);
        insert(node);
        return node->value;
    }
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            node->value = value;
            remove(node);
            insert(node);
            return;
        }
        Node* node = new Node(key, value);
        mp[key] = node;
        insert(node);
        if (mp.size() > capacity) {
            Node* lru = tail->prev;
            mp.erase(lru->key);
            remove(lru);
            delete lru;
        }
    }
};