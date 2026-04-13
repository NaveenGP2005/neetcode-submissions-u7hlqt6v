class LRUCache {
  private:
  class Node {
public:
    int key, val;
    Node* prev;
    Node* next;

    Node(int _key, int _val) {
        key = _key;
        val = _val;
        prev = next = nullptr;
    }
};
  public:
   unordered_map<int, Node*> m;
    int capacity;
    Node* head;
    Node* tail;

    void addNode(Node* node) {
        // Add node right after head
        Node* nextNode = head->next;
        head->next = node;
        node->prev = head;
        node->next = nextNode;
        nextNode->prev = node;
    }

    void deleteNode(Node* node) {
        // Remove node from list
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

public:
    LRUCache(int cap) {
        capacity = cap;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (m.find(key) == m.end()) {
            return -1;
        }

        Node* node = m[key];
        int value = node->val;

        // Move to front
        deleteNode(node);
        addNode(node);

        return value;
    }

    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            // Key exists, delete old node
            Node* oldNode = m[key];
            deleteNode(oldNode);
            delete oldNode;
            m.erase(key);
        }

        if (m.size() == capacity) {
            // Remove LRU from end
            Node* lru = tail->prev;
            deleteNode(lru);
            m.erase(lru->key);
            delete lru;
        }

        // Add new node
        Node* newNode = new Node(key, value);
        addNode(newNode);
        m[key] = newNode;
    }
};