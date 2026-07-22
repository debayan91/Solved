class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        vector<int> res(k, 0);
        unordered_map<int, unordered_set<int>> m;
        for(auto& a : logs){
            m[a[0]].insert(a[1]);
        }
        for(auto& [a, b] : m){
            int index = b.size() - 1;
            res[index]++;
        }
        return res;
    }
};