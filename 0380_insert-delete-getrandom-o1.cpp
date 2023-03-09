class RandomizedSet {
public:
    RandomizedSet() {
        srand(time(nullptr));
    }

    bool insert(int val) {
        if (index.count(val)) {
            return false;
        }
        index[val] = nums.size();
        nums.push_back(val);
        return true;
    }

    bool remove(int val) {
        if (!index.count(val)) {
            return false;
        }
        int pos = index[val];
        index[nums.back()] = pos;
        nums[pos] = nums.back();
        nums.pop_back();
        index.erase(val);
        return true;
    }

    int getRandom() {
        return nums[rand() % nums.size()];
    }

    vector<int> nums;
    unordered_map<int, int> index;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
