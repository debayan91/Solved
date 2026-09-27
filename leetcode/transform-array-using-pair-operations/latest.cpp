class Solution {
public:
    bool canTransform(vector<int>& s, vector<int>& t) {
        return accumulate(begin(s), end(s), 0LL) == accumulate(begin(t), end(t), 0LL);
    }
};