class RandomizedSet {
    vector<int> nums;
    unordered_map<int, int> m;

public:
    bool insert(int val) {
        if (m.count(val)) return false;
        m[val] = nums.size();
        nums.push_back(val);
        return true;
    }

    bool remove(int val) {
        if (!m.count(val)) return false;

        int last = nums.back();
        nums[m[val]] = last;
        m[last] = m[val];

        nums.pop_back();
        m.erase(val);
        return true;
    }

    int getRandom() { return nums[rand() % nums.size()]; }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */