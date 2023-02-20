class MyHashMap {
public:
    MyHashMap() {
    }
    
    void put(int key, int value) {
        int index = key % base;
        ListNode* head = &data[index];
        while (head->next != nullptr) {
            if (head->next->key == key) {
                head->next->val = value;
                return;
            }
            head = head->next;
        }
        head->next = new ListNode;
        head->next->key = key;
        head->next->val = value;
    }
    
    int get(int key) {
        int index = key % base;
        ListNode* head = &data[index];
        while (head->next != nullptr) {
            if (head->next->key == key) {
                return head->next->val;
            }
            head = head->next;
        }
        return -1;
    }
    
    void remove(int key) {
        int index = key % base;
        ListNode* head = &data[index];
        while (head->next != nullptr) {
            if (head->next->key == key) {
                ListNode* tmp = head->next;
                head->next = head->next->next;
                delete tmp;
                return;
            }
            head = head->next;
        }
    }
    
    struct ListNode {
        int key = -1;
        int val = -1;
        ListNode* next = nullptr;
        };
    
    static const int base = 997;
    
    array<ListNode, base> data;
    
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
