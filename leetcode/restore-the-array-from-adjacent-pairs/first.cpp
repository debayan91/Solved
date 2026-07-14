class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adj) {
        unordered_map<int, vector<int>> m;
        vector<int> res;
        for(auto& a : adj){
            int x = a[0];
            int y = a[1];
            if(m[x].size() == 0 || m[x].back() != y) m[x].push_back(y);
            if(m[y].size() == 0 || m[y].back() != x) m[y].push_back(x);
        }
        for(auto& [a, b] : m){
            if(size(b) == 1){
                // either start or end -> start exploring from this point
                res.push_back(a); // the start
                int last = a;
                if(size(m) > 1) res.push_back(b[0]); // its only neighbor
                while(size(res) < m.size()){
                    int clast = res.back();
                    for(int i : m[clast]){
                        if(i != last){
                            res.push_back(i);
                        }
                    }
                    last = clast;
                }
                //
                break;
            }
        }
        return res;
    }
};