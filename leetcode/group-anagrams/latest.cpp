class Solution {
public:
    string counts(string s) {
        // vector<int> res(26);
        // for(char c : s){
        //     res[c - 'a']++;
        // }
        // return string(res.begin(), res.end());
        string key(26, '0');
        for (char c : s) {
            key[c - 'a']++;
        }
        return key;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // vector<string> hash;
        // for (string s : strs) {
        //     hash.push_back(counts(s));
        // }
        unordered_map<string, vector<string>> m;
        for (int i = 0; i < strs.size(); i++) {
            m[counts(strs[i])].push_back(strs[i]);
        }
        vector<vector<string>> res;
        for (const auto& [key, value] : m) {
            res.push_back(value);
        }
        return res;
    }
};