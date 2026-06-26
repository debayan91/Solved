class Solution {
public:
    string mergeCharacters(string s, int k) {
        bool mergeable = false;
        unordered_map<char, vector<int>> u;
        for(int i = 0; i < size(s); i++){
            if(size(u[s[i]]) >= 1 && !mergeable){
                int a = u[s[i]].back();
                if(i - a <= k){
                    mergeable = true;
                }else{
                    u[s[i]].push_back(i);
                }
            }else{
                u[s[i]].push_back(i);
            }
        }
        if(!mergeable){
            return s;
        }
        fill(s.begin(), s.end(), '.');
        for(auto& [c, v] : u){
            for(int i : v){
                s[i] = c;
            }
        }
        string r = "";
        for(char c : s){
            if(c != '.'){
                r += c;
            }
        }
        return mergeCharacters(r, k);
    }
};