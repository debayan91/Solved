class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> map;
        for(int i = 0; i < s.size(); i++){
            if(map.count(s[i]) != 0) if(t[i] != map[s[i]]) return false;
            map[s[i]] = t[i];
        }
        map.clear();
        swap(s, t);
        for(int i = 0; i < s.size(); i++){
            if(map.count(s[i]) != 0) if(t[i] != map[s[i]]) return false;
            map[s[i]] = t[i];
        }
        return true;
    }
};