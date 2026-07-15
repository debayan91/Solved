class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> m;
        vector<string> res;
        for(auto& w : words){
            if(m.count(w) == 0) res.push_back(w);
            m[w]++;
        }
        sort(begin(res), end(res), [&](string a, string b){
            if(m[a] == m[b]) return a < b;
            else return m[a] > m[b];
        });
        while(res.size() > k) res.pop_back();
        return res;
    }
};