class Solution {
public:
    vector<int> relativeSortArray(vector<int>& a, vector<int>& b) {
        map<int, int> m;
        for(int i : a) m[i]++;
        string s = "";
        vector<int> res;
        for(int i = 0; i < size(b); i++){
            if(m.count(b[i])){
                while(m[b[i]]--) res.push_back(b[i]);
            }
        }
        for(auto& [x, y] : m){
            if(y > 0){
                while(y--) res.push_back(x);
            }
        }
        return res;
    }
};