/*
Design and implement a data structure for LRU (Least Recently Used) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reaches its capacity, it should invalidate the least recently used item before inserting the new item.
The LRU Cache will be initialized with an integer corresponding to its capacity. Capacity indicates the maximum number of unique keys it can hold at a time.

Definition of “least recently used” : An access to an item is defined as a get or a set operation of the item. “Least recently used” item is the one with the oldest access time.
*/

class Node {
    public:
    int key;
    int val;
    Node* prev;
    Node* next;
    Node(int k, int v) {
        key = k;
        val = v;
        prev = NULL;
        next = NULL;
    }
};
 
Node* head;
Node* tail;
int cap;
map<int, Node*> m;
int cur_size;
 
LRUCache::LRUCache(int capacity) {
    cap = capacity;
    head = NULL;
    tail = NULL;
    m.clear();
    cur_size = 0;
}
 
Node* updateList(Node* head, Node* cur) {
    if (cur == head) return head;
    if (cur == tail){
        tail = tail->prev;
        tail->next = NULL;
    }
    if (cur->prev)cur->prev->next = cur->next;
    if (cur->next)cur->next->prev = cur->prev;
    cur->next = head;
    head->prev = cur;
    head = cur;
    head->prev = NULL;
    return head;
}
 
int LRUCache::get(int key) {
    if (m.find(key) == m.end()) return -1;
    head = updateList(head, m[key]);
    return m[key]->val;
}
 
void LRUCache::set(int key, int value) {
    if (m.find(key) == m.end()){
        if (cur_size == cap) {
            Node* del = tail;
            if (head == tail) {
                head = NULL;
                tail = NULL;
            } else {
                tail = tail->prev;
                tail->next = NULL;
            }
            m.erase(del->key);
            cur_size--;
        }
        Node* cur = new Node(key, value);
        m[key] = cur;
        if (head == NULL){
            head = cur;
            tail = cur;
        } else {
            cur->next = head;
            head->prev = cur;
            head = cur;
            head->prev = NULL;
        }
        cur_size ++;
    } else {
        m[key]->val = value;
        head = updateList(head, m[key]);
    }
    return;
 
}
