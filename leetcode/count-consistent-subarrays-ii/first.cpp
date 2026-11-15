class Solution {
public:
    long long countConsistent(vector<int>& nums) {
        int n = size(nums);
        long long total = 0;
        vector<pair<int, int>> g;
        //map<int, int> m;
        vector<int> m(1000069, -1);
        for (int i = 0; i < n; i++) {
            m[nums[i]] = i; // r
            vector<pair<int, int>> h;
            for (auto& [a, b] : g) {
                int w = a & nums[i];
                if(!size(h) || h.back().first != w) h.push_back({w, b});
            }
            if(!size(h) || h.back().first != nums[i]) h.push_back({nums[i], i});
            g = move(h);
            for(int j = 0; j < size(g); j++){
                auto [a, l] = g[j]; int r = j + 1 < size(g) ? g[j + 1].second - 1 : i;
                if(m[a] >= l) total += min(r, m[a]) - l + 1;
            }
        }
        return total;
    }
};