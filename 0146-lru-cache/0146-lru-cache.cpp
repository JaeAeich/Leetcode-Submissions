class Node {
public:
    int key;
    int val;
    Node* prev;
    Node* next;
    
    Node(int key, int val) {
        this->key = key;
        this->val = val;
        this->prev = nullptr;
        this->next = nullptr;
    }
};


class LRUCache {
private:
    int cap;
    unordered_map<int, Node*> m;
    Node* dummyHead;
    Node* dummyTail;
    
public:
    LRUCache(int capacity) {
        cap = capacity;
        dummyHead = new Node(-1, -1);
        dummyTail = new Node(-1, -1);
        dummyHead->next = dummyTail;
        dummyTail->prev = dummyHead;
    }
    
    int get(int key) {
        if (m.find(key) == m.end()) {
            return -1;
        }
        // Move the accessed item to the front of the cache.
        Node* node = m[key];
        removeNode(node);
        addToFront(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            // Key exists, update value and move it to the front.
            Node* node = m[key];
            node->val = value;
            removeNode(node);
            addToFront(node);
        } else {
            if (m.size() == cap) {
                // Remove the least recently used node from the end of the cache.
                Node* removed = removeFromEnd();
                m.erase(removed->key);
                delete removed;
            }
            // Add the new node to the front of the cache.
            Node* newNode = new Node(key, value);
            m[key] = newNode;
            addToFront(newNode);
        }
    }

private:
    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    
    void addToFront(Node* node) {
        node->next = dummyHead->next;
        node->prev = dummyHead;
        dummyHead->next->prev = node;
        dummyHead->next = node;
    }

    Node* removeFromEnd() {
        Node* removed = dummyTail->prev;
        removeNode(removed);
        return removed;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */