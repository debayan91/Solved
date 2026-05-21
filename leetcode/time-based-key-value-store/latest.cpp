class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> map;
    // key - timestamp - value

    TimeMap() {}

    string search(vector<pair<int, string>>& v, int target, int l, int h) {

        auto it = upper_bound(v.begin(), v.end(), target,
                              [](int target, const pair<int, string>& p) {
                                  return target < p.first;
                              });

        if (it == v.begin()) {
            return ""; // no timestamp <= target
        }

        --it;
        return it->second;
    }

    void set(string key, string value, int timestamp) {
        map[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        // vector<pair<int, string>> v = map[key];
        if (map[key].size() == 0)
            return "";
        return search(map[key], timestamp, 0, map[key].size() - 1);
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */