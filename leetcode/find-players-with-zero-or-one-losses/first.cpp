class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> mp;
        for(vector<int>& v : matches){
            mp[v[1]]++;
            mp[v[0]];
        }
        vector<vector<int>> o(2);
        for(auto& [a, b] : mp){
            if(b == 0) o[0].push_back(a);
            if(b == 1) o[1].push_back(a);
        }
        sort(begin(o[0]), end(o[0]));
        sort(begin(o[1]), end(o[1]));
        return o;
    }
};