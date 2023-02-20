
class MyHashSet {
public:
    MyHashSet() {
    }
    
    void add(int key) {
        data.set(key);
    }
    
    void remove(int key) {
        data.reset(key);
    }
    
    bool contains(int key) {
        return data.test(key);
    }
private:
    
    static constexpr int size = 1000005;
    bitset<size> data;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
