class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        unordered_map<int, int> m1;
        for(auto a : nums1) m1[a[0]] += a[1];
        for(auto a : nums2) m1[a[0]] += a[1];
        vector<vector<int>> v;
        for(auto [a, b] : m1){
                v.push_back({a, m1[a]});
        }
        sort(begin(v), end(v), [](auto a, auto b){
            return a[0] < b[0];
        });
        return v;
    }
};