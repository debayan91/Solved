class Solution {
public:
    struct hash_vec {
        size_t operator()(const vector<int>& v) const {
            size_t h = 0;

            for (int x : v) {
                h = h * 31 + hash<int>()(x);
            }

            return h;
        }
    };

    unordered_set<vector<int>, hash_vec> st;
    vector<int> nums;
    void backtrack(vector<int>& current, vector<bool>& v, int index) {
        if (index == nums.size()) {
            st.insert(current);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!v[i]) {
                v[i] = true;
                current[i] = nums[index];
                backtrack(current, v, index + 1);
                v[i] = false;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        this->nums = nums;
        vector<int> current(nums.size());
        vector<bool> v(nums.size());
        vector<vector<int>> res;
        backtrack(current, v, 0);
        for(vector<int> i : st) res.push_back(i);
        return res;
    }
};